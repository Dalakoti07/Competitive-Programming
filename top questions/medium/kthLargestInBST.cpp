using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
int ans=-1;
void findKthLargestValueInBstHelper(BST *tree, int k,vector<int>& sorted) {
	if(tree==NULL)
		return;
	if(sorted.size()==k)
		return ;
	findKthLargestValueInBstHelper(tree->right,k,sorted);
	if(sorted.size()<k){
		sorted.push_back(tree->value);
		findKthLargestValueInBstHelper(tree->left,k,sorted);
	}
	return;
}

int findKthLargestValueInBst(BST *tree, int k) {
	vector<int> sorted;
	findKthLargestValueInBstHelper(tree,k,sorted);
	return sorted[sorted.size()-1];
}
