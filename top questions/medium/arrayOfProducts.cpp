vector<int> arrayOfProducts(vector<int> arr) {
  // Write your code here.
	vector<int> answer(arr.size(),1);
	int product=1;
	for(int i=1;i<arr.size();i++){
		product*=arr[i-1];
		answer[i]=product;
	}
	product=1;
	cout<<"arr after one pass \n";
	for(int i: answer)
			cout<<i<<" ";
	product=arr[arr.size()-1];
	for(int i=arr.size()-2;i>=0;i--){
		answer[i]*=product;
		product*=arr[i];
	}
	cout<<"arr after 2nd pass \n";
	for(int i: answer)
			cout<<i<<" ";
  return answer;
}