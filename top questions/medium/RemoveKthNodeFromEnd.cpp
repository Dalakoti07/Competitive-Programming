#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
	int index=0;
	LinkedList* forward=head;
	LinkedList* slower=head;
	while(index!=k){
		forward=forward->next;
		index++;
	}
	if(forward==nullptr){
		//cout<<"first elem need to be removed";
		//means first element need to be removed
		head->value=head->next->value;
		head->next=head->next->next;
		return;
	}
	while(forward!=nullptr and forward->next!=nullptr){
		forward=forward->next;
		slower=slower->next;
	}
	slower->next=slower->next->next;
}
