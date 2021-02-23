using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBst(vector<int> arr) {
  // Write your code here.
	int len=arr.size();
	if(len==0)
		return NULL;
	if(len==1)
		return new BST(arr[0]);
	int mid=len/2;
	vector<int>leftArr(arr.begin(),arr.begin()+mid);
	vector<int>rightArr(arr.begin()+mid+1,arr.end());
	BST* root=new BST(arr[mid]);
	root->left=minHeightBst(leftArr);
	root->right=minHeightBst(rightArr);

	return root;
}
