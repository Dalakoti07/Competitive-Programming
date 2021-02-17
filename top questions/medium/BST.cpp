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

  BST &remove(int val) {
    // Write your code here.
    if(value==val){
			//remove this node
			
		}else if(val<value)
			this.left.remove(val);
		else
			this.right.remove(val);

		// Do not edit the return statement of this method.
		return *this;
  }
};