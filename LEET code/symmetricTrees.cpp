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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else 
            return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left==NULL and right ==NULL)
            return true;
        else if(left==NULL || right==NULL)
            return false;
        else if(left->val != right->val) 
            return false;
        else 
            return isSymmetric(left->left,right->right) and  isSymmetric(left->right,right->left);
    }
};