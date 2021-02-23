class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBst(BST *tree,int min=INT_MIN,int max=INT_MAX) {
  // Write your code here.
	if(tree==NULL)
		return true;
	if(tree->value>=max || tree->value<min)
		return false;
	if(tree->left!=NULL and tree->value<=tree->left->value)
		return false;
	if(tree->right!=NULL and tree->value>tree->right->value)
		return false;
	return validateBst(tree->left,min,tree->value) and validateBst(tree->right,tree->value,max);
}
