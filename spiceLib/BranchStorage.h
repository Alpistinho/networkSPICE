/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::BranchStorage
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\BranchStorage.h
*********************************************************************/

#ifndef BranchStorage_H
#define BranchStorage_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
#include "Spice.h"
//## class BranchStorage
#include "Storage.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation addBranch(unsigned long)
    class Branch;
    
    //## package Spice
    
    //## class BranchStorage
    class BranchStorage : public Storage {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        BranchStorage();
        
        //## auto_generated
        ~BranchStorage();
        
        ////    Operations    ////
        
        //## operation addBranch(unsigned long)
        Branch* addBranch(unsigned long identifier);
        
        //## operation allocateBranchNumbers(unsigned long)
        void allocateBranchNumbers(unsigned long firstPosition);
        
        //## operation getBranchAmount()
        unsigned long getBranchAmount();
        
        ////    Additional operations    ////
        
        //## auto_generated
        std::map<unsigned long, Branch*> getBranchMap() const;
        
        //## auto_generated
        void setBranchMap(std::map<unsigned long, Branch*> p_branchMap);
        
        ////    Attributes    ////
    
    protected :
    
        std::map<unsigned long, Branch*> branchMap;		//## attribute branchMap
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\BranchStorage.h
*********************************************************************/
