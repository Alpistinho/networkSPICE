#include "OneBranchComponent.h"
#include "Branch.h"
namespace Spice {

    OneBranchComponent::OneBranchComponent() {
        branches = NULL;
    }
    
    OneBranchComponent::~OneBranchComponent() {
        cleanUpRelations();
    }
    
    void OneBranchComponent::cleanUpRelations() {
        if(branches != NULL)
            {
                branches = NULL;
            }
    }
    
    OneBranchComponent::OneBranchComponent(Branch* newBranch) {
        branches = NULL;
        branches = newBranch;
        
    }
}