#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    // Write your code here.
		if(val<this.value){
			if(this.left==nullptr)
				this.left= new BST(val);
			else
				this.left->insert(val);
		}else{
			if(this.right==nullptr)
				this.right=new BST(val);
			else
				right->insert(val);
		}
    // Do not edit the return statement of this method.
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
		if(this.value==val)
			return true;
		bool res;
		if(this.left!=nullptr)
			res=contains(this.left);
		if(res)
			return true;
		if(this.right!=nullptr)
			res=contains(this.right);
		if(res)
			return true
		
    return false;
  }

  BST &remove(int val,BST& parent=NULL) {
    // Write your code here.
    if(value==val){
			//remove this node
			
			// if val has only one child
			if(parent!=NULL){
				if(left==NULL){
					parent->right=right;
					//free();
					return *this;
				}
				if(right==NULL){
					parent->left=left;
					return *this;
				}
				val=getMinVal(right);
				right.remove(val,this);
				return *this;
			}else{
				if(left==NULL)
					return right;
				if(right==NULL)
					return left;
				val=getMinVal(right);
				right.remove(val,this);
				return *this;
			}
				
			
		}else if(val<value)
			this.left.remove(val,this);
		else
			this.right.remove(val,this);

		// Do not edit the return statement of this method.
		return *this;
  }
	
	int getMinVal(){
		if(left==NULL)
			return val;
		else
			return left.getMinVal();
	}
};
