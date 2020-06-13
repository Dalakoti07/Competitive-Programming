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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1=head, *ptr2=head;
        // create sepration between ptr1 and ptr2 as n
        int count=0;
        if(n==0)
            return head;
        while(count!=n){
            ptr2=ptr2->next;
            count++;
        }
        if(ptr2==NULL){
            if(ptr1->next==NULL)
                return NULL;
            else
                return head->next;
        }
        // now inc both ptr until ptr2 is not at the end
        while(ptr2->next !=NULL){
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        // remove the node and do connection
        // if(ptr1->next->next!=NULL)
            ptr1->next=ptr1->next->next;
        return head;
    }
};