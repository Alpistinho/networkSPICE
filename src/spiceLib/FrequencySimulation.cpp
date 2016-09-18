#include "FrequencySimulation.h"
#include "ComponentStorage.h"

namespace Spice {
    
    using namespace std;
    
    FrequencySimulation::FrequencySimulation() {
        results = nullptr;
    }
    
    FrequencySimulation::~FrequencySimulation() {
    }
    
    std::map<double,std::vector<std::complex<double>>*> * FrequencySimulation::simulateFrequencyResponse(ComponentStorage* componentStorage) {
        if(results) {
            delete results; //delete old results
        }
        results = new std::map<double, std::vector<std::complex<double>>*>; //allocate new result
        double frequencyStep = pow(2.0,1.0/(points));
        componentStorage->allocateNodeNumbers();
        unsigned long systemSize = componentStorage->getSystemSize();
        
        //holds the matrix that will be solved
        vector<vector<complex<double>>> equationSystem;
        for(double currentFrequency = initFreq ; currentFrequency <= endFreq; currentFrequency *= frequencyStep) {
            componentStorage->getFrequencySystem(&equationSystem, currentFrequency);
        	(*results)[currentFrequency] = solveEquationSystem(equationSystem);
        }
        
        return results;
        
    }
    
    std::vector<std::complex<double>>* FrequencySimulation::solveEquationSystem(std::vector<std::vector<std::complex<double>>>& equationSystem) {
        unsigned long rows = equationSystem.size();
        unsigned long columns = rows + 1;
        
        unsigned long a;
        
        complex<double> biggest, pivot; //  nomes esclarecedores!
        
        
        for (unsigned long i = 1; i < rows; i++) {
        
        	biggest = 0;
        	a = i;
        
        	for (unsigned long l = i; l < rows; l++) {         					//  percorre a matriz, da linha de interesse ao final,
        		if (abs(equationSystem[l][i]) > abs(biggest)) { 	//  procurando qual o maior valor na coluna de interesse
        			a = l;					    				//  guarda em 'a', qual a linha do maior valor desta coluna
        			biggest = equationSystem[l][i];					//	e em 't' qual o valor do maior elemento da coluna
        		}												//  o valor de 'i'  que percorre as columns
        	}
        	if (i != a) {										// 'i' agora diz a linha em que estamos trabalhando
        	  for (unsigned long l = 1; l < columns; l++) {					// coloca a linha com maior pivo para cima
        		pivot = equationSystem[i][l];
        		equationSystem[i][l] = equationSystem[a][l];
        		equationSystem[a][l] = pivot;
        	  }
        	}
        
        	if (abs(biggest) < tolerance) {;
        		//don't know what to do yet
        		//singular matrix
        	}
        
        	for (unsigned long j = (columns - 1) ; j > 0; j--) {  /* Basta j>i em vez de j>0 */
        	  equationSystem[i][j] /= biggest	;		  // divide um elemento pelo maior elemento de maior valor desta coluna, percorre da ultima coluna para a primeira
        	  pivot=equationSystem[i][j];			  // guarda o valor do elemento j dividido em 'p'
        
        	  for (unsigned long l = 1; l < rows; l++) {
        		if (l != i)			  //remove das demais rows ('!i')
        			equationSystem[l][j]-= (equationSystem[l][i]*pivot);
        	  }
        	}
        }
        
        vector<complex<double>>* result;
        result = new vector<complex<double>>;
        for (unsigned long i = 1; i < rows; i++) {
        	result->push_back(equationSystem[i][columns - 1]);
        }
        
        return result;
        
    }
    
    double FrequencySimulation::getEndFreq() const {
        return endFreq;
    }
    
    void FrequencySimulation::setEndFreq(double p_endFreq) {
        endFreq = p_endFreq;
    }
    
    double FrequencySimulation::getInitFreq() const {
        return initFreq;
    }
    
    void FrequencySimulation::setInitFreq(double p_initFreq) {
        initFreq = p_initFreq;
    }
    
    unsigned long FrequencySimulation::getPoints() const {
        return points;
    }
    
    void FrequencySimulation::setPoints(unsigned long p_points) {
        points = p_points;
    }
    
    void FrequencySimulation::setResults(std::map<double,std::vector<std::complex<double>>*> * p_results) {
        results = p_results;
    }
    
    std::map<double,std::vector<std::complex<double>>*> * FrequencySimulation::getResults() const {
        return results;
    }
}