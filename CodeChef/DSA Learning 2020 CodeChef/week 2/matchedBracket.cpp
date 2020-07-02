#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

void test_case(){
    int n; cin >> n;
    vector<int> arr=vector<int>(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int maxDepth=0,maxDepthIdx=-1,count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            if(count>maxDepth){
                maxDepth=count;
                maxDepthIdx=i+1;
            }
        }else{
            count--;
        }
    }
    // now find the maxLength of subsequence and its starting index, see how beautifully its done
    int kiska[n];
    memset(kiska,-1,sizeof(kiska));
    stack<pair<int,int>> whichTypeAndLength;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            whichTypeAndLength.push({1,i});
        }else{
            if(!whichTypeAndLength.empty() and whichTypeAndLength.top().first==1){
                kiska[whichTypeAndLength.top().second]=i;
                whichTypeAndLength.pop();
            }
        }
    }

    // max length and idx
    int maxLength=0,maxLengthIdx=-1;
    for(int i=0;i<n;i++){
        if(kiska[i]!=-1){
            int len= kiska[i]-i+1;
            if(len>maxLength){
                maxLength=len;
                maxLengthIdx=i+1;
            }
        }
    }
    cout<<maxDepth<<" "<<maxDepthIdx<<" "<<maxLength<<" "<<maxLengthIdx;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}
