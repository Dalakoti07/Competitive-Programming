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
    // https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/549891/BT-and-BST-C%2B%2B-Solution%3A-Preorder-Comma-seperated-with-comments
public:
    // Encodes a tree to a single string.
    // encoding will be like 1->2->N->3
    string serialize(TreeNode* root) {
        if(root==NULL) return "N";
        return to_string(root->val) +","+ serialize(root->left) +","+ serialize(root->right);
    }

    int getTheVal(string& data){
        int pos=data.find(',');
        int val=stoi(data.substr(0,pos));
        data=data.substr(pos+1);
        return val;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeHelper(string& data){
        if(data[0]=='N'){
            if(data.size()>1)
                data=data.substr(2);
            return NULL;
        }
        int val=getTheVal(data);
        // cout<<" val : "<<val<<endl;
        TreeNode* root= new TreeNode(val);
        root->left=deserializeHelper(data);
        root->right=deserializeHelper(data);
        return root;
    }

    TreeNode* deserialize(string data) {
        return deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));a