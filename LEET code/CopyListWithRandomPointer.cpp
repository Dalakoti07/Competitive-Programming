/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        // count the nodes
        int count=0;
        Node* iter=head;
        // NodeAddressIndexWise.push_back(iter);
        while(iter!=NULL){
            count++;
            iter=iter->next;
        }

        vector<Node*> NodeAddressIndexWise(count);
        // first iteration
        iter=head;
        // NodeAddressIndexWise.push_back(iter);
        while(iter!=NULL){
            Node* randomNodePointingTo =iter->random;
            randomNodeAddress.push_back(iter);
            iter=iter->next;
        }
        cout<<"all nodes count: "<<NodeAddressIndexWise.size()<<endl;
        Node* newList= new Node(head->val);
        Node* newListIter= newList;
        while(head->next!=NULL){
            newListIter->random=head->random;
            newListIter->next=head->next;
            newListIter=newListIter->next;
            head=head->next;
        }
    }
};