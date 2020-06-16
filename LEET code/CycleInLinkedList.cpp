/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head==NULL) return false;
        if(head->next==NULL) return false;
        ListNode *slow,*fast;// fast speed is 2x
        slow=head;
        fast=head->next;
        while(slow!=fast){
            if(fast==NULL){
                return false;
            }
            if(slow!=NULL)
                slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next->next;
            }else
                fast=fast->next;
        }
        return true;
    }
};