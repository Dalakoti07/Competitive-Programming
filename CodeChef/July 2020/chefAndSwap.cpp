#include<bits/stdc++.h>
using namespace std;

void printArrays(int* arr1,int* arr2,int start,int end){
    cout<<"arr one \n";
    for(int i=start;i<=end;i++)
        cout<<arr1[i]<<" ";
    cout<<"\narray two\n";
    for(int i=start;i<=end;i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
}

// changing the start, not changing the arr pointer
int go(int* arr1,int* arr2,int start,int end){
    // start and end both are inclusive
    if(start==end){
        if(arr1[start]==arr2[start])
            return 0;
        else return -1;
    }
    // printArrays(arr1,arr2,start,end);
    int count=0;
    if(arr1[start]==arr2[start])
        return go(arr1,arr2,start+1,end);
    else{
        // see if swaping is beneficial and if beneficial then do it and call rec
        // if swapping arr1[start] and arr2[start+1] is beneficial
        int one=INT_MAX,two=INT_MAX;
        if(arr2[start+1]==arr2[start]){
            swap(arr1[start],arr2[start+1]);
            // cout<<"after swapping\n ";
            // printArrays(arr1,arr2,start,end);
            one=go(arr1,arr2,start+1,end);
            swap(arr1[start],arr2[start+1]);
            // cout<<"reversing swapping\n ";
            // printArrays(arr1,arr2,start,end);
            if(one==-1){
                one=INT_MAX;
            }else{
                one+=1;
            }
        }
        // if swapping arr2[start] and arr1[start+1]
        if(arr1[start+1]==arr1[start]){
            swap(arr1[start+1],arr2[start]);
            two=go(arr1,arr2,start+1,end);
            swap(arr1[start+1],arr2[start]);
            if(two==-1){
                two=INT_MAX;
            }else
                two+=1;
        }
        if(two==INT_MAX and one==INT_MAX) return -1;
        return min(one,two);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        cout<<go(arr1,arr2,0,n-1)<<"\n";
    }
}