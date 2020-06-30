 void levelOrder(Node * root) {
        if(root==NULL) return;
        queue<Node*> allNodes;
        allNodes.push(root);
        while(! allNodes.empty()){
            vector<Node*> vec=vector<Node*>();
            while(!allNodes.empty()){
                vec.push_back(allNodes.front());
                allNodes.pop();
            }
            for(int i=0;i<vec.size();i++){
                cout<<vec[i]->data<<" ";
                if(vec[i]->left!=NULL)
                    allNodes.push(vec[i]->left);
                if(vec[i]->right!=NULL)
                    allNodes.push(vec[i]->right);
            }
        }
        return;
    }