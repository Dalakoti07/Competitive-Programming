/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void doThreading(Node* root, Node* nextNode){
        if(root==NULL) return;
        root->next=nextNode;
        doThreading(root->left,root->right);
        if(nextNode!=NULL){
            doThreading(root->right,nextNode->left);
        }else{
            doThreading(root->right,NULL);
        }
    }

    Node* connect(Node* root) {
        doThreading(root, NULL);
        return root;
    }
};