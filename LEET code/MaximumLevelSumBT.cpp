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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxy=INT_MIN;
        int idx=1,ans=1;
        stack<TreeNode*> allNodes;
        allNodes.push(root);
        // maxy=max(maxy,root->val);
        while(!allNodes.empty()){
            // take all nodes out of stack and add their value and 
            vector<TreeNode*> nodesInStack;
            int count =0;
            while(!allNodes.empty()){
                count+=allNodes.top() -> val;
                nodesInStack.push_back(allNodes.top());
                allNodes.pop();
            }
            if(maxy<count){
                maxy=count;
                ans=idx;
            }
            idx++;
            // put the children of nodesInStack in allNodes
            for(int i=0;i<nodesInStack.size();i++){
                if(nodesInStack[i]->left != NULL){
                    allNodes.push(nodesInStack[i]->left);
                }
                if(nodesInStack[i]->right!=NULL){
                    allNodes.push(nodesInStack[i]->right);
                }
            }
        }
        return ans;
    }
};