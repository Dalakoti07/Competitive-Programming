#include<bits/stdc++.h>
using namespace std;

void printTheArray(vector<int> arr){
    cout<<"\nthe arr is \n";
    for(auto i: arr)
        cout<<i<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // create partition set
    set<int> partitionSubset;
    partitionSubset.insert(1);
    for(int i=1;i<n;i++){
        if(arr[i]%arr[i-1] !=0)
            partitionSubset.insert(i+1);
    }
    int type,idx,x;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>idx>>x;
            // check if new replaced element create new partition on the left side or right side of existing partitions

            // check if updated element merges with left partition
            if(idx>1){
                // general case
                if( x% arr[idx-2] !=0){
                    partitionSubset.insert(idx);
                }else{
                    // new element is in set , no new partiotion formed at idx, if there was a partition starting at this point remove it
                    partitionSubset.erase(idx);
                }
            }

            // check on right if it merges with that right partition
            if(idx<n){
                if(arr[idx]%x == 0){
                    // idx+1 cannot be starting of new index as we have starting early, so remove it
                    partitionSubset.erase(idx+1);
                }else{
                    // idx+1 is new starting of partition
                    partitionSubset.insert(idx+1);
                }
            }
            // update the array
            arr[idx-1]=x;
        }else{
            // print the start idx of that subarray type
            cin>>idx;
            auto itr= partitionSubset.upper_bound(idx);
            itr--;
            cout<<*itr<<endl;
        }
    }
}