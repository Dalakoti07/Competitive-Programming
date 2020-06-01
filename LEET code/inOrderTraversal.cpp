#include<bits/stdc++.h>
using namespace std;
// recursive solution
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root==NULL){
//             return vector<int>();
//         }else{
//             vector<int> answer;
//             answer=inorderTraversal(root->left);
//             answer.push_back(root->val);
//             vector<int> rightRec= inorderTraversal(root->right);
//             for(int i :rightRec){
//                 answer.push_back(i);
//             }
//             return answer;
//         }
//     }
// };

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer= vector<int>();
        stack<TreeNode*> recStack;
        TreeNode* currentNode=root;
        while(currentNode!=NULL or recStack.empty()==false){
            while(currentNode!=NULL){
                recStack.push(currentNode);
                currentNode=currentNode->left;
            }
            // now currentNode is null
            currentNode= recStack.top();
            recStack.pop();
            answer.push_back(currentNode->val);
            currentNode=currentNode->right;
        }
        return answer;
    }
};



int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct TreeNode *root = new TreeNode(1); 
    root->left        = new TreeNode(2); 
    root->right       = new TreeNode(3); 
    root->left->left  = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    Solution* solution = new Solution();

    vector<int> answer= solution->inorderTraversal(root); 
    for(int x :answer){
        cout<<x<<"\n";
    }
    return 0; 
} 