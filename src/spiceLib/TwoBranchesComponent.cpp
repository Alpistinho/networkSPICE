#include "TwoBranchesComponent.h"
#include "Branch.h"
namespace Spice {

    
    TwoBranchesComponent::TwoBranchesComponent(Branch** newBranches) {
        {
            for (int pos = 0; pos < 2; pos++) {
            	branches[pos] = NULL;
            }
        }
        branches[0] = newBranches[0];
        branches[1] = newBranches[1];
        
    }
    
    TwoBranchesComponent::TwoBranchesComponent() {
        {
            for (int pos = 0; pos < 2; pos++) {
            	branches[pos] = NULL;
            }
        }
    }
    
    TwoBranchesComponent::~TwoBranchesComponent() {
        cleanUpRelations();
    }
    
    void TwoBranchesComponent::cleanUpRelations() {
    }
}