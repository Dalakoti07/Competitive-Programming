using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    LinkedList* head=nullptr;
	LinkedList* curr=nullptr;
	int carry=0,sum;
	while(linkedListOne!=nullptr and linkedListTwo!=nullptr){
		sum=linkedListOne->value + linkedListTwo->value + carry;
		carry=sum/10;
		sum=sum%10;
		if(head==nullptr){
			head=new LinkedList(sum);
			curr=head;
		}else{
			LinkedList* newNode=new LinkedList(sum);
			curr->next=newNode;
			curr=curr->next;
		}
		linkedListOne=linkedListOne->next;
		linkedListTwo=linkedListTwo->next;
	}
	while(linkedListOne!=nullptr){
		sum=linkedListOne->value + carry;
		carry=sum/10;
		LinkedList* newNode=new LinkedList(sum);
		curr->next=newNode;
		curr=curr->next;
		linkedListOne=linkedListOne->next;
	}
	while(linkedListTwo!=nullptr){
		sum=linkedListTwo->value + carry;
		carry=sum/10;
		LinkedList* newNode=new LinkedList(sum);
		curr->next=newNode;
		curr=curr->next;
		linkedListTwo=linkedListTwo->next;
	}
	if(carry!=0){
		LinkedList* newNode=new LinkedList(carry);
		curr->next=newNode;
		curr=curr->next;
	}
    return head;
}