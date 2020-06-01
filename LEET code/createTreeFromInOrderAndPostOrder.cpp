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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       return buildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
    }

    TreeNode* buildTree(vector<int>& inorder,int i,int j, vector<int>& postorder,int x,int y) {
        if(i>=j or x>=y) 
            return NULL;
        int rootValue = postorder[y-1];
        auto f = find(inorder.begin()+i,inorder.begin()+j,rootValue);
        int distance = f - inorder.begin() - i;

        TreeNode* left = buildTree(inorder, i,i+distance,postorder,x,x+distance);
        TreeNode* right = buildTree(inorder,i+distance+1,j,postorder,x+distance,y-1);

        TreeNode* root = new TreeNode(rootValue,left,right);
        return root;
    }
};