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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* reversedList=reverseList(head->next);
        // get to the last of reversed list and then put it there
        ListNode* iter=reversedList;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        iter->next=head;
        iter->next->next=NULL;
        return reversedList;
    }

    void printList(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }

    bool compareTwoList(ListNode* one,ListNode* two){
        printList(one);
        printList(two);
        while(one!=NULL and two!=NULL){
            if(one->val!=two->val) return false;
            one=one->next;
            two=two->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        int count=0;
        if(head==NULL) return true;
        if(head->next==NULL) return true;
        ListNode* iter=head;
        while(iter!=NULL){
            count++;
            iter=iter->next;
        }
        ListNode *firstHalf,*secondHalf; 
        if(count%2==0){
            ListNode* temp;
            int mid = count/2-1;
            firstHalf=head;
            temp=head;
            while(mid!=0){
                temp=temp->next;
                mid--;
            }
            secondHalf=temp->next;
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
        secondHalf=reverseList(secondHalf);
        return compareTwoList(firstHalf,secondHalf);
    }
};