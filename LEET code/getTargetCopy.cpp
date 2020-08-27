/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // its an exhaustive search with recursion
        if(original==NULL) return NULL;
        if(original==target) return cloned;

        TreeNode* leftRec=getTargetCopy(original->left,cloned->left,target);
        TreeNode* rightRec=getTargetCopy(original->right,cloned->right,target);
        if(! leftRec)
            return rightRec;
        else
            return leftRec;
        return NULL;
    }
};