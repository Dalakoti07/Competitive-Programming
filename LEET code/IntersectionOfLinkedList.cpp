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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB==NULL) return NULL;
        if(headA==headB) return headA;

        ListNode* one =getIntersectionNode(headA->next,headB);
        if(one!=NULL) return one;
        ListNode* two =getIntersectionNode(headA,headB->next);
        if(two!=NULL) return two;
        ListNode* three =getIntersectionNode(headA->next,headB->next);
        if(three!=NULL) return three;
        return NULL;
    }
};