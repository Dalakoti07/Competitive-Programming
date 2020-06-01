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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) 
            return vector<vector<int>>();
        vector<vector<int>> answer =vector<vector<int>>();
        vector<int> thisNode =vector<int>{root->val};
        answer.push_back(thisNode);

        vector<vector<int>> lTreeResult= levelOrder(root->left);
        vector<vector<int>> rTreeResult =levelOrder(root->right);
        // merge the results
        for(int i=0;i<min(lTreeResult.size(),rTreeResult.size());i++){
            vector<int> _vec= vector<int>(lTreeResult[i]);
            _vec.insert(_vec.end(),rTreeResult[i].begin(),rTreeResult[i].end());
            answer.push_back(_vec);
        }
        // if leftResult > rightResult, then merge the remaining left result as it is to answer
        if(lTreeResult.size()>rTreeResult.size()){
            for(int i=rTreeResult.size();i<lTreeResult.size();i++){
                answer.push_back(lTreeResult[i]);
            }
        }
        // if rightResult > leftResult, then merge the remaining right result as it is to answer
        if(rTreeResult.size()>lTreeResult.size()){
            for(int i=lTreeResult.size();i<rTreeResult.size();i++){
                answer.push_back(rTreeResult[i]);
            }
        }
        return answer;
    }
};