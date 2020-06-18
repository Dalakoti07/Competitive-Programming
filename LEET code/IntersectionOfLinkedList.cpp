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
        // make hashtable, from listA
        unordered_map<ListNode*,bool> nodes;
        ListNode* iter=headA;
        while(iter!=NULL){
            nodes[iter]=true;
            iter=iter->next;
        }
        // make hashtable from listB
        iter=headB;
        while(iter!=NULL){
            if(nodes.count(iter)==1) return iter;
            iter=iter->next;
        }
        return NULL;
    }
};