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
    void kthSmallest(TreeNode* root, int k,vector<int>& arraySoFar){
        int n =arraySoFar.size();
        if(n==k+1) return; 
        if(root==NULL) return;
        kthSmallest(root->left,k,arraySoFar);
        arraySoFar.push_back(root->val);
        kthSmallest(root->right,k,arraySoFar);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arraySoFar;
        kthSmallest(root,k,arraySoFar);
        return arraySoFar[k-1];
    }
};