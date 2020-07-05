#include<bits/stdc++.h>
using namespace std;

long long go(vector<int>& arr,int start,int end){
    if(start>=end) return 0;

    // cout<<"start : "<<start<<" and end : "<<end<<"\n";
    int mid =(start+end)/2;
    long long leftConflicts = go(arr,start,mid);
    long long rightConflicts= go(arr,mid+1,end);
    long long ans =leftConflicts+rightConflicts;
    long long countOfConflictAtJoining=0;
    // merge the array 
    vector<int> temp(end-start+1);
    // left arr
    /*
    cout<<"\n left array\n";
    for(int i=start;i<=mid;i++)
        cout<<arr[i]<<" ";
    cout<<"\n right array\n";
    for(int i=mid+1;i<=end;i++)
        cout<<arr[i]<<" ";
    */
    int i=start,j=mid+1,k=0;
    while(k!=temp.size() and i!=mid+1 and j!=end+1){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            countOfConflictAtJoining+=(mid+1-i);
            // cout<<" count: "<<countOfConflictAtJoining<<" ";
        }
    }
    // cout<<"\n"; 
    while(i!=mid+1){
        temp[k++]=arr[i++];
    }
    while(j!=end+1){
        temp[k++]=arr[j++];
    }
    // copy temp array to arr
    k=start;
    // cout<<" after merge : ";
    for(auto i:temp){
        // cout<<i<<" ";
        arr[k++]=i;
    }
    // cout<<"\n left ans "<<leftConflicts<<" and right ans "<<rightConflicts<< " conflict when joining "<<countOfConflictAtJoining<< "\n";
    // cout<<" start : "<<start<<" end : "<<end<<" ans: "<<ans+countOfConflictAtJoining<<" \n";

    return ans+countOfConflictAtJoining;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];
    // using divide and conquer, after getting hint :(
    cout<<go(arr,0,n-1)<<endl;
}