#include<bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};
struct Wrapper{
	bool isBalanced;
	int height;
};

Wrapper heightOfTree(BinaryTree* node);

bool heightBalancedBinaryTree(BinaryTree *tree) {
    // Write your code here.
	Wrapper ans=heightOfTree(tree);
    return ans.isBalanced;
}

Wrapper heightOfTree(BinaryTree* node){
	if(node==nullptr){
		return Wrapper{true,0};
	}
	Wrapper leftTree=heightOfTree(node->left);
	Wrapper rightTree=heightOfTree(node->right);
	if(leftTree.isBalanced==false){
		return Wrapper{false,max(leftTree.height,rightTree.height)};
	}
	if(rightTree.isBalanced==false){
		return Wrapper{false,max(leftTree.height,rightTree.height)};
	}
	bool isBalanced=true;
	if(abs(rightTree.height-leftTree.height)>1){
		isBalanced=false;
	}
	return Wrapper{isBalanced,max(leftTree.height,rightTree.height)+1};
}
