#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    long long int ans=0;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    for(int i=2;i<n;i++){
        int elem =arr[i],j,k;
        for(j=i-1;j>=0 and elem>=arr[j];j--){
            
        }
        if(j!=-1){
            for(k=i+1;k<=n and elem>= arr[k];k++){
                
            }
            if(k!=n+1){
                ans=max(ans,1ll*k*j);
                // cout<<"update "<<ans<<endl;
            }
        }
    }
    cout<<ans;
    return 0;
}
