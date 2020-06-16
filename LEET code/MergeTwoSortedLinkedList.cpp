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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right){
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
           ListNode* nextRightSideNode=right;
           ListNode* nextLeftSideNode= left;
           while(nextRightSideNode->next !=NULL or nextRightSideNode->val < left->val){
               nextRightSideNode= nextRightSideNode->next;
           }
            left->next= mergeTwoLists(nextLeftSideNode,nextRightSideNode->next);
            nextRightSideNode->next=left;
            cout<<"after merge ";
            printList(right);
            return right;
        }else{
           ListNode* nextRightSideNode=right;
           ListNode* nextLeftSideNode= left;
           while(nextLeftSideNode->next!=NULL or nextLeftSideNode->val < right->val){
               nextLeftSideNode=nextLeftSideNode->next;
           }
            right->next= mergeTwoLists(nextRightSideNode,nextLeftSideNode->next);
            nextLeftSideNode->next=right;
            cout<<"after merge ";
            printList(left);
            return left;
        }
    }
};