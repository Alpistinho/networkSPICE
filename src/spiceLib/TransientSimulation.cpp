#include "TransientSimulation.h"
#include "ComponentStorage.h"

namespace Spice {

    
    
    using namespace std;
    
    TransientSimulation::TransientSimulation() {
    }
    
    TransientSimulation::~TransientSimulation() {
    }
    
    std::vector<std::pair<double, std::vector<double>>>* TransientSimulation::simulateTransientResponse(ComponentStorage* componentStorage, std::vector<double> initialConditions) {

        results = vector<pair<double, vector<double>>>(); //clear result

        results.push_back(pair<double, vector<double>>(0.0, initialConditions));

        componentStorage->allocateNodeNumbers();

        //holds the matrix that will be solved
        vector<vector<double>> equationSystem;


        for(double currentTime = step; currentTime <= endTime; currentTime += step) {
            vector<double> pastResults = results.back().second;
            componentStorage->getTransientSystem(&equationSystem, &pastResults, step, currentTime);
            results.push_back(pair<double, vector<double>>(currentTime, *solveEquationSystem(equationSystem)));
        }

        
        return &results;
        
    }
    
    //delete old results
    
    //allocate new result
    
    //holds the matrix that will be solved
    
    //delete old results
    
    //allocate new result
    
    //holds the matrix that will be solved
    
    std::vector<double>* TransientSimulation::solveEquationSystem(std::vector<std::vector<double>>& equationSystem) {
        //#[ operation solveEquationSystem(std::vector<std::vector<double>>&)
        unsigned long rows = equationSystem.size();
        unsigned long columns = rows + 1;
                
        unsigned long a;
                
        double biggest, pivot; //  nomes esclarecedores!
                


        for (unsigned long i = 1; i < rows; i++) {
                
            biggest = 0;
            a = i;
                
            for (unsigned long l = i; l < rows; l++) {         					//  percorre a matriz, da linha de interesse ao final,
                if (abs(equationSystem[l][i]) > abs(biggest)) { 	//  procurando qual � o maior valor na coluna de interesse
                	a = l;					    				//  guarda em 'a', qual a linha do maior valor desta coluna
                	biggest = equationSystem[l][i];					//	e em 't' qual o valor do maior elemento da coluna
                }												//  o valor de 'i' � que percorre as columns
            }
            if (i != a) {										// 'i' agora diz a linha em que estamos trabalhando
                for (unsigned long l = 1; l < columns; l++) {					// coloca a linha com maior piv� para cima
                pivot = equationSystem[i][l];
                equationSystem[i][l] = equationSystem[a][l];
                equationSystem[a][l] = pivot;
                }
            }
                
            if (abs(biggest) < tolerance) {
                //don't know what to do yet
                //singular matrix
            }
                
            for (unsigned long j = (columns - 1) ; j > 0; j--) {  /* Basta j>i em vez de j>0 */
                equationSystem[i][j] /= biggest	;		  // divide um elemento pelo maior elemento de maior valor desta coluna, percorre da ultima coluna para a primeira
                pivot=equationSystem[i][j];			  // guarda o valor do elemento j� dividido em 'p'
                
                for (unsigned long l = 1; l < rows; l++) {
                if (l != i)			  //remove das demais rows ('!i')
                	equationSystem[l][j]-= (equationSystem[l][i]*pivot);
                }
            }
        }
                


        vector<double>* result;
        result = new vector<double>;
        result->push_back(0);
        for (unsigned long i = 1; i < rows; i++) {
            result->push_back(equationSystem[i][columns - 1]);
        }
        return result;
        
    }
    
    double TransientSimulation::getEndTime() const {
        return endTime;
    }
    
    void TransientSimulation::setEndTime(double p_endTime) {
        endTime = p_endTime;
    }
    
   std::vector<std::pair<double, std::vector<double>>>* TransientSimulation::getResults()  {
        return &results;
    }
    
    void TransientSimulation::setResults(std::vector<std::pair<double, std::vector<double> > > p_results) {
        results = p_results;
    }
    
    double TransientSimulation::getStep() const {
        return step;
    }
    
    void TransientSimulation::setStep(double p_step) {
        step = p_step;
    }
}