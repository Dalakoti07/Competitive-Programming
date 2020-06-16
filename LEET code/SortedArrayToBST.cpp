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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n =nums.size();
        if(n==0) return NULL;
        if(n==1) return new TreeNode(nums[0]);
        int mid =n/2;
        TreeNode* root = new TreeNode(nums[mid]);
        auto iter=nums.begin()+ (mid-1);
        vector<int> leftSubArray= vector<int>(nums.begin(),iter);// 0 to mid -1
        vector<int> rightSubArray= vector<int>(iter+2,nums.end());// mid+1 to end
        root->left = sortedArrayToBST(leftSubArray); 
        root->right= sortedArrayToBST(rightSubArray); 
        return root;
    }
};