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
    int printList(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
        return 0;
    }

    ListNode* mergeList(ListNode* left, ListNode* right){
        // problem in merging [5] and [3,4]
        cout<<"left :";
        printList(left);
        cout<<"right:";
        printList(right);
        if(left==NULL or right==NULL){
            if(left==NULL) return right;
            else return left;
        }
        if(left->val > right->val){
           ListNode* nextRightSideNode=right->next;
           ListNode* nextLeftSideNode= left->next;
            right->next=left;
            left->next= mergeList(nextLeftSideNode,nextRightSideNode);
            cout<<"after merge ";
            printList(right);
            return right;
        }else{
           ListNode* nextRightSideNode=right->next;
           ListNode* nextLeftSideNode= left->next;
            left->next=right;
            right->next= mergeList(nextLeftSideNode,nextRightSideNode);
            cout<<"after merge ";
            printList(left);
            return left;
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        // merge sort technique
        int length=0;
        ListNode* iter=head;
        while(iter!=NULL){
            length++;
            iter=iter->next;
        }
        // go to half the list size
        int mid =length/2 -1 ,count=0;
        ListNode *right,*left;
        iter=head;
        while(count!=mid){
            count++;
            iter=iter->next;
        }
        left=head;
        right=iter->next;
        iter->next=NULL;
        // recursive call
        left=sortList(left);
        right=sortList(right);

        // merge the lists
        return mergeList(left,right);
    }
};