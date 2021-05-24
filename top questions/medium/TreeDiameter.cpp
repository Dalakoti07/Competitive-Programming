#include<bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

struct TreeInfo{
	int diameter;
	int height;
};

TreeInfo getTreeInfo(BinaryTree* node){
	if(node==nullptr){
		return TreeInfo{0,0};
	}
	TreeInfo leftTree=getTreeInfo(node->left);
	TreeInfo rightTree=getTreeInfo(node->right);
	int diameterThroughNode=leftTree.height + rightTree.height;
	int diameter=max(leftTree.diameter,rightTree.diameter);
	return TreeInfo{max(diameter,diameterThroughNode),max(leftTree.height,rightTree.height)+1};
}

int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  return getTreeInfo(tree).diameter;
}
