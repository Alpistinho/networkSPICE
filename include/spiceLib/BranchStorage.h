#ifndef BranchStorage_H
#define BranchStorage_H


#include <string>
#include <algorithm>

#include "Spice.h"
#include "Storage.h"

namespace Spice {
   
	class Branch;

	class BranchStorage : public Storage {
		
	public :
	
		BranchStorage();
		

		~BranchStorage();
		
		Branch* addBranch(unsigned long identifier);
		
		void allocateBranchNumbers(unsigned long firstPosition);
		
		unsigned long getBranchAmount();
		
		std::map<unsigned long, Branch*> getBranchMap() const;
		
		void setBranchMap(std::map<unsigned long, Branch*> p_branchMap);
		
	
	protected :
	
		std::map<unsigned long, Branch*> branchMap;
	};
}

#endif

