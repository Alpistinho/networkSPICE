

#ifndef BJT_H
#define BJT_H

#include <string>
#include <algorithm>

#include "Spice.h"

#include "ThreeTerminalsComponent.h"


namespace Spice {

    class Node;

}


////

namespace Spice {

    class BJT : public ThreeTerminalsComponent {

        
    public :
    

        BJT(Node** newNodes, double hfe, double hie, double hre, double hoe, double cbe, double cbc, unsigned long newKey);

        BJT();

        virtual ~BJT();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        

        int getCbc() const;

        void setCbc(int p_cbc);
        
        int getCbe() const;
        
        void setCbe(int p_cbe);
        
        int getHfe() const;
        
        void setHfe(int p_hfe);

        int getHie() const;
        
        void setHie(int p_hie);
        
        int getHoe() const;
        
        void setHoe(int p_hoe);
        
        int getHre() const;
        
        void setHre(int p_hre);
        
    
    protected :
    
        int cbc;	
        
        int cbe;	
        
        int hfe;
        
        int hie;
        
        int hoe;
        
        int hre;
    
    public :
    
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif

