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
    void helper(TreeNode* root,vector<pair<int,int>>& heightAndValues,int h){
        if(root==nullptr) return;
        
        heightAndValues.push_back({h,root->val});
        helper(root->left,heightAndValues,h+1);
        helper(root->right,heightAndValues,h+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        // we can make a vector<pair<int,int>> where we have {depth,value}
        vector<pair<int,int>> heightAndValues;
        helper(root,heightAndValues,0);

        // sort the arr
        sort(heightAndValues.begin(),heightAndValues.end());// default sort by .first
        reverse(heightAndValues.begin(),heightAndValues.end());
        int greatHeight=heightAndValues[0].first;
        int sum=0;
        // for(int i=0;i<heightAndValues.size() ;i++){
        //     cout<<heightAndValues[i].first<<" "<<heightAndValues[i].second<<endl;
        // }
        for(int i=0;i<heightAndValues.size() ;i++){
            if(heightAndValues[i].first!=greatHeight)
                break;
            sum+=heightAndValues[i].second;
        }
        return sum;
    }
};