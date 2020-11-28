#include <iostream>
using namespace std;

int go(int arr[],int n,int k){
    int minLen=n+1,currSum=0;
    int start=0,end=0;
    while(end<n){
        while(currSum<=k and end<n)
            currSum+=arr[end++];
            
        //if sum becomes greater than k
        while(currSum>k and start<n){
            if(end-start<minLen)
                minLen=end-start;
            currSum-=arr[start++];
        }
    }
    return minLen;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<go(arr,n,k)<<endl;
	}
	return 0;
}