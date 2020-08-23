/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // it can be done with rec, rec would give vector<pair<Node*,Node*>> of size 2, which sends head to odd and even list
    // and their tails corresponding <h1,t1>,<h2,t2>
    // then the complexity would be Tn = T(n/2) + T(n/2) + n/2

    // but we want n complexity, thus we will use 4 pointers evenHead,evenTail, oddHead, oddTail
    // and we will traverse the list and we will do the needful 
    ListNode* oddEvenList(ListNode* head) {
        
        // covering the edge cases
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        if(head->next->next==NULL) return head;

        ListNode *evenHead,*evenTail, *oddHead, *oddTail;
        // wont change
        oddHead=head;
        
        // wont be changed
        evenHead=head->next;
        
        evenTail=head->next;
        oddTail=head;
        bool isOdd=true;
        ListNode *temp=evenHead->next;
        while(temp!=NULL){
            if(isOdd){
                oddTail->next=temp;
                oddTail=oddTail->next;
            }else{
                evenTail->next=temp;
                evenTail=evenTail->next;
            }
            temp=temp->next;
            isOdd=!isOdd;
        }
        evenTail->next=NULL;
        oddTail->next=evenHead;
        return oddHead;
    }
};