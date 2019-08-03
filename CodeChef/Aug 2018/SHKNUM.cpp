// partially accepted
// one thing to note here is that two operations are negate of each other, thus we would either
// add or subtract only, not both
// We would precompute the list which has all possible values of x^a + y^b ,and then we would 
// apply binary search or (simple one by one approach would do trick as array size if 300 something) to get the results

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	// precompute
	vector<int> nums;
	for(int i=0;i<=30;i++)
		for(int j=i+1;j<=30;j++){
			nums.push_back((1<<i)+(1<<j));
		}
	sort(nums.begin(), nums.end());
	// for(int i=0;i<nums.size();i++){
	// 	cout<<nums[i]<<" ";
	// }
	int index;
	while(t--){
		cin>>n;
		for(int i=0;i<nums.size();i++)
			if(nums[i]>=n)
				{index=i-1;break;}
		cout<<min(nums[index+1]-n,n-nums[index])<<endl;
	}
}