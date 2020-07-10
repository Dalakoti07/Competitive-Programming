#include<bits/stdc++.h>
using namespace std;

// https://discuss.codechef.com/t/chefsqrs-editorial/59476
// great explanation



// the problem with this approach is that given n =10^8 in worst case we have may have 
// valid perfect square at 10^9 lets say and for that we cannot make that big array
/*
vector<int> allPerfectSquares;

void preCompute(){
    int n=1;
    while(n<=(int)1e4){
        allPerfectSquares.push_back(n*n);
        n++;
    }
}
int solve(){
    int n;
    cin>>n;
    if(n==1) return -1;
    auto itr=upper_bound(allPerfectSquares.begin(),allPerfectSquares.end(),n);
    int startIdx=itr-allPerfectSquares.begin();
    for(int i=startIdx;i<allPerfectSquares.size();i++){
        if(find(allPerfectSquares.begin(),allPerfectSquares.end(),allPerfectSquares[i]-n)!=allPerfectSquares.end()){
            return allPerfectSquares[i]-n;
        }
    }
    return -1;
}
*/

long long solve(){
    long long n;
    cin>>n;
    long long one,two,ans=INT_MAX;
    bool isPossible=false;
    for(long long i=1;i<sqrt(n);i++){
        one=i;
        if(n%i==0)
            two=n/i;
        else
            continue;
        // cout<<"factor "<<one<<" "<<two<<" \n";
        if((two-one)/2 == 0) continue;
        
        if((two-one)%2==0){
            if(ans==INT_MAX){
                ans=(two-one)/2;
                isPossible=true;
            }
            else
                ans=min((two-one)/2,ans);
        }
    }
    if(ans==INT_MAX) return -1;
    return ans*ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}