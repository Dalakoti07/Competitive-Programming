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
    bool compareTwoList(ListNode* one,ListNode* two){
        while(one!=NULL and two!=NULL){
            if(one->val!=two->val) return false;
            one=one->next;
            two=two->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        int count=0;
        if(head->next==NULL) return head;
        ListNode* iter=head;
        while(iter!=NULL){
            count++;
            iter=iter->next;
        }
        ListNode *firstHalf,*secondHalf; 
        if(count%2==0){
            ListNode* temp;
            int mid = count/2;
            firstHalf=head;
            temp=head;
            while(mid!=0){
                temp=temp->next;
                mid--;
            }
            secondHalf=temp;
            temp->next=NULL;
        }else{
            int mid=count/2 -1;
            ListNode* temp=head;
            firstHalf=head;
            while(mid!=0){
                temp=temp->next;
                mid--;
            }
            secondHalf=temp->next->next;
            temp->next=NULL;
        }
        return compareTwoList(firstHalf,secondHalf);
    }
};