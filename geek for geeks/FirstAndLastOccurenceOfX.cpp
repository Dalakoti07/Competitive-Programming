#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,x,first=-1,last=-1;
	    cin>>n>>x;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        if(first==-1 and arr[i]==x){
	            first=i;
	            last=i;
	        }
	        else if(arr[i]==x and first!=1){
	            last=i;
	        }
	    }
	    if(first!=-1)
	        cout<<first<<" "<<last<<endl;
	    else
	        cout<<-1<<endl;
	}
	return 0;
}