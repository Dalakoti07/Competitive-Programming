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
    int summation=0;
    void helper(TreeNode* root,TreeNode* parent,TreeNode* grandParent){
        if(root==NULL) return;
        if(grandParent!=NULL and (grandParent->val)%2==0)
            summation+=root->val;
        helper(root->left,root,parent);
        helper(root->right,root,parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        helper(root,NULL,NULL);
        return summation;
    }
};