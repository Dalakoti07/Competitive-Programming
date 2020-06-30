#include <bits/stdc++.h>
using namespace std;

long long maxSubarray(vector<long long>& arr, long long n, long long m){ 
    long long x, prefix = 0, maxim = 0; 
  
    set<long long> S; 
    S.insert(0);
  
    // Traversing the array. 
    for (long long i = 0; i < n; i++){ 
        // Finding prefix sum. 
        prefix = (prefix + arr[i])%m; 

        // Finding maximum of prefix sum. 
        maxim = max(maxim, prefix); 
  
        // Finding iterator point longing to the first  
        // element that is not less than value  
        // "prefix + 1", i.e., greater than or  
        // equal to this value. 
        auto it = S.lower_bound(prefix+1); 
  
        if (it != S.end()) 
            maxim = max(maxim, prefix - (*it) + m ); 
  
        // Inserting prefix in the set. 
        S.insert(prefix); 
    } 
  
    return maxim; 
} 

// wa
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long q,n,m;
    cin>>q;
    while(q--){
        cin>>n>>m;
        vector<long long> arr=vector<long long>(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxSubarray(arr,n,m)<<endl;
    }

    return 0;
}
