#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int i,idx=-1;
        for(i=n-2;i>0;i--){
            if(arr[i]<arr[i+1]){
                idx=i;
                break;
            }
        }
        cout<<"valley at "<<idx<<endl;
        if(idx==-1){
            // sort arr
            sort(arr.begin(),arr.end());
        }else{
            int x=arr[idx];
            int justBigger=-1,diff=INT_MAX;
            for(i=idx+1;i<n;i++){
                if(arr[i]-x<diff){
                    justBigger=i;
                    diff=arr[i]-x;
                }
            }
            cout<<"found just bigger at "<<justBigger<<endl;
            swap(arr[idx],arr[justBigger]);
            sort(arr.begin()+idx+1,arr.begin()+n);
        }
        //print answer
        for(int a:arr)
            cout<<a<<" ";
        cout<<endl;
    }
	return 0;
}