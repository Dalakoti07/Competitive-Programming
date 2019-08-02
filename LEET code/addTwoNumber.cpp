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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* temp1=l1;
    ListNode* temp2=l2;
    ListNode* resultHead=new ListNode(((temp1->val)+(temp2->val))%10);
    ListNode* temp3=resultHead;
    carry=((temp1->val)+(temp2->val))/10;
    temp1=temp1->next;
    temp2=temp2->next;
    while(temp1!=NULL and temp2!=NULL){
    	temp3->next=new ListNode(((temp1->val)+(temp2->val)+carry)%10);
    	carry=((temp1->val)+(temp2->val)+carry)/10;
    	temp3=temp3->next;
    	temp1=temp1->next;
    	temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
    	temp3->next=new ListNode(((temp1->val)+carry)%10);
    	carry=((temp1->val)+carry)/10;
    	temp3=temp3->next;
    	temp1=temp1->next;
    }
 	while(temp2!=NULL)
    {
    	temp3->next=new ListNode(((temp2->val)+carry)%10);
    	carry=((temp2->val)+carry)/10;
    	temp3=temp3->next;
    	temp2=temp2->next;
    }
    if(carry>0){
    	temp3->next=new ListNode(carry);
    	temp3=temp3->next;
    }
    return resultHead;
    }
};