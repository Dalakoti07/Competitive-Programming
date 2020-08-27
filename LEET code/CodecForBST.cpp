/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/549891/BT-and-BST-C%2B%2B-Solution%3A-Preorder-Comma-seperated-with-comments
    // Encodes a tree to a single string.
    void serializehelper(TreeNode* root, string& s){
        if(root==nullptr) return;
        
        s+=to_string(root->val) + ","; // ',' for seperating each value
        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        string s="";
        serializehelper(root, s);
        
        return s;
    }
    int getTheVal(string& data,int& pos){
        pos=data.find(',');
        int val=stoi(data.substr(0,pos));
        return val;
    }

    TreeNode* deserializeHelper(string& data,int min,int max){
        if(data.size()==0) return NULL;
        int pos=0,val;
        val=getTheVal(data,pos);
        if(val<min or val>max){//outof bound thus not valid number
            return NULL;
        }
        TreeNode* root= new TreeNode(val);
        // pass the data
        data=data.substr(pos+1);
        root->left=deserializeHelper(data,min,val);
        root->right=deserializeHelper(data,val,max);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        return deserializeHelper(data,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));