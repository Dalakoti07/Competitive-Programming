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
    int sum=0;
    vector<char> zeroAndOne;
    void printVec(){
        for(char c:zeroAndOne)
                cout<<c<<" ";
        cout<<endl;
    }
    string getStringFromVec(){
        string binStr="";
        for(char c:zeroAndOne)
            binStr+=c;
        return binStr;
    }
    void helper(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            zeroAndOne.push_back(root->val ? '1':'0');
            string binaryString="";
            // cout<<"binarystring: atbase case";
            // printVec();
            sum+=stoi(getStringFromVec(),0,2);
            zeroAndOne.pop_back();
            return;
        }
        zeroAndOne.push_back(root->val ? '1':'0');
        // zeroAndOne.push_back(root->val);
        // printVec();
        if(root->left!=NULL)
            sumRootToLeaf(root->left);
        if(root->right!=NULL)
            sumRootToLeaf(root->right);
        zeroAndOne.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        helper(root);
        return sum;
    }
};