#include<bits/stdc++.h>

using namespace std;

vector<int> precomputeVector;

void precompute(int n){
    precomputeVector.clear();
    for(int i=1;i<=10;i++){
        precomputeVector.push_back(pow(i,n));
    }
}

// Complete the powerSum function below.
int powerSum(int X, int N,vector<int>& memoizationArray) {
    // cout<<"loop 17";
    // check if X is of form a^b, make a helper function
    if(X==1) return 1;
    if(X<N) return 0;
    if(X==N){
        if(find(precomputeVector.begin(),precomputeVector.end(),X)!=precomputeVector.end())
            return 1;
        return 0;
    }
    cout<<"called with X: "<<X<<" and N: "<<N<<"\n";
    if(memoizationArray[X]!=-1) return memoizationArray[X];
    int count =0;
    if(find(precomputeVector.begin(),precomputeVector.end(),X)!=precomputeVector.end()){
        count++;
    }

    for(int i=1;i<=X/2;i++){
        cout<<" one :"<<powerSum(i,N,memoizationArray)<<" two " <<powerSum(X-i,N,memoizationArray)<<endl;
        count+=powerSum(i,N,memoizationArray)*powerSum(X-i,N,memoizationArray);
    }
    memoizationArray[X]=count;
    cout<<"called with X: "<<X<<" and N: "<<N<<" and res is "<<count<<"\n";
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,n;
        cin>>x>>n;
        precompute(n);
        vector<int> memoizationArray(x+1,-1);
        cout<<" \nans: "<<powerSum(x,n,memoizationArray)<<endl;
    }
    return 0;
}
