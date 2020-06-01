/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) 
            return vector<TreeNode*>();
        return generateTrees(1,n);
    }

    vector<TreeNode*> generateTrees(int start,int end){
        vector<TreeNode*> trees= vector<TreeNode*>();
        if(start>end){
            trees.push_back(NULL); // important to return NULL , if return empty array without null then its problematic
            return trees;
        }
        else if (start==end){
            trees.push_back(new TreeNode(start));
            return trees;
        }else{
            for(int i=start;i<=end;i++){// every node from start to end would be root at-least once
                vector<TreeNode*> allLeftPossibleTrees= generateTrees(start,i-1);
                vector<TreeNode*> allRightPossibleTrees= generateTrees(i+1,end);
                // TreeNode* root = new TreeNode(i);// with root-value as i
                // generate all trees with root as value i and combining all possible left and right tree
                for (auto leftTree : allLeftPossibleTrees){
                    for (auto rightTree: allRightPossibleTrees){
                        TreeNode* root = new TreeNode(i);// with root-value as i
                        root->left = leftTree;
                        root->right= rightTree;
                        trees.push_back(root); 
                    }
                } 
            }
            return trees;
        }
    }
};