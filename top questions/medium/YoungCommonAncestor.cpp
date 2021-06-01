#include <vector>
using namespace std;

class AncestralTree {
public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
    }
	
  void addAsAncestor(vector<AncestralTree *> descendants);
};

int depthOfNode(AncestralTree* topAncestor, AncestralTree* descendant){
		int depth=0;
		while(descendant!=topAncestor){
			depth++;
			descendant=descendant->ancestor;
		}
		return depth;
}

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,AncestralTree *descendantOne,AncestralTree *descendantTwo) {
	int depth1= depthOfNode(topAncestor,descendantOne);
	int depth2= depthOfNode(topAncestor,descendantTwo);
	
	if(depth1<depth2){
		while(depth2!=depth1){
			descendantTwo=descendantTwo->ancestor;
			depth2--;
		}
	}else if(depth2<depth1){		
		while(depth2!=depth1){
			descendantOne=descendantOne->ancestor;
			depth1--;
		}
	}
	// now they are on same level
	while(descendantOne!=descendantTwo){
		descendantOne=descendantOne->ancestor;
		descendantTwo=descendantTwo->ancestor;
	}
	return descendantOne;
}
