#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n<2){
        cout<<"Invalid Input\n";
        return 0;
    }
    sort(arr.begin(),arr.end());
    if(arr[0]==arr[n-1])
        cout<<"Equal\n";
    else{
        cout<<arr[0]<<" "<<arr[1]<<endl;
    }
}