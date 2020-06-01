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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder,int i,int j,vector<int>& inorder,int x,int y){
        // first element in preOrder is root
        if(i>=j or x>=y)
            return NULL;
        int rootValue = preorder[i];
        // find split in inOrder tree array
        auto f = find(inorder.begin() + x,inorder.begin() + y,rootValue);
        int distance = f - inorder.begin() - x;

        TreeNode* left =buildTree(preorder, i+1,i+1+distance ,inorder,x,x+distance);
        TreeNode* right = buildTree(preorder, i+distance+1,j ,inorder,x+distance+1,y);

        TreeNode* root = new TreeNode(rootValue,left,right);
        return root;
    }
};