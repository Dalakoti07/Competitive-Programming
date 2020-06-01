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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) 
            return vector<vector<int>>();
        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool leftToRight=true;
        while(nodeQueue.empty()!=true){
            int size =nodeQueue.size();
            // nodeQueue stores current level all nodes
            vector<int> row =vector<int>(size);// this vector array of size same as elems in Queue would store the result for each row, in right order, reverse or unreversed

            // fill the array
            for(int i=0;i<size;i++){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                int index =(leftToRight)? i : (size-1-i); 
                row[index]=node->val;
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);
            }
            leftToRight= ! leftToRight;
            result.push_back(row);
        }
        return result;
    }
};