#include<bits/stdc++.h>
using namespace std;
long long dp[53][53][1400];

long long solve(long long idx,long long sum,long long curLen,long long length){
	if(sum<0) return 0;
	if(curLen==length and sum==0) return 1;
	if(curLen==length and sum!=0) return 0;
	if(idx==53) return 0;
	if(dp[idx][curLen][sum]!=-1) return dp[idx][curLen][sum];
	long long ans = solve(idx+1,sum-idx,curLen+1,length) + solve(idx+1,sum,curLen,length);
	return dp[idx][curLen][sum]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    long long t;
    cin>>t;
    for(int f=1; f<=t; f++){
        long long l,s;
        cin>>l>>s;
        cout<<"Case "<<f<<": ";
        if(l>52 || s>1400) cout<<0<<endl;
        else cout<<solve(1,s,0,l)<<endl;
    }
    return 0;
}