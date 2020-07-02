#include <bits/stdc++.h>
using namespace std;

// https://discuss.codechef.com/t/notallfl-editorial/54855

int main() {
	int t;
	cin>>t;
	while(t--){
        int n,k;
		cin>>n>>k;
		// one vector to count occurence of values in the current subarray
		// one var for count of unique elements
		vector<int> arr=vector<int>(n);
		int uniqueCountTillNow=0,ans=0;
		vector<int> occurenceCount=vector<int>(k+1,0);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int left=0,right=0;
		for(;left<n;left++){
			// see if we can extend
			while(right<n and (uniqueCountTillNow<k-1 or occurenceCount[arr[right]])){
				if(occurenceCount[arr[right]]==0){
					uniqueCountTillNow+=1;
				}
				occurenceCount[arr[right]]++;
				right++;
			}
			//update answer
			ans= max(ans,right-left);
			// remove arr[left] from consideration
			occurenceCount[arr[left]]--;
			if(occurenceCount[arr[left]]==0)
				uniqueCountTillNow--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}