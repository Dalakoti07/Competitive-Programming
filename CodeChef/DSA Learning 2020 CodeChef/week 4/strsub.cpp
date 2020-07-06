#include<bits/stdc++.h>
using namespace std;

void preCompute(string seq, int k,vector<long long>& sumArray,vector<long long>& far){
    // sumarray store array prefix sum and far vec store at which index sequence break 
    long long i=0,j=0,count0=0,count1=0,n=seq.length();
    if(seq[i]=='0')
        count0++;
    else
        count1++;
    for(;i<n;i++){
        while(j<n and count1<=k and count0<=k){
            j+=1;
            if(seq[j]=='0')
                count0++;
            else
                count1++;
        }
        // cout<<" i: "<<i<<" j: "<<j<<"\n";
        far[i+1]=j;
        sumArray[i+1]=sumArray[i]+j;

        if(seq[i]=='0') count0--;
        else count1--;
    }
}

long long getAnswer(vector<long long>& sumFar,vector<long long>& far,long long a, long long b) {
    auto start = far.begin()+a;
    auto end = far.begin()+b;
    auto it = prev(lower_bound(start,end,b));
    
    long long in = it-far.begin();
    long long l = end - (it);
    // equation from editorial
    long long temp = (b*(b-a+1)) - ((sumFar[in]-sumFar[a-1])+(b*l));
    long long ans = ((b-a+1)*(b-a+2))/2 - temp;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k,q,a,b;
        cin>>n>>k>>q;
        string seq;
        cin>>seq;
        vector<long long> sumArray(n+1,0), far(n+1,0);
        preCompute(seq,k,sumArray,far);
        /*cout<<" far array \n";
        for(long long i=1;i<=n;i++)
            cout<<far[i]<<" ";
        cout<<"\n sum array \n";
        for(long long i=1;i<=n;i++)
            cout<<sumArray[i]<<" ";
        cout<<"\n";*/
        for(int i=0;i<q;i++){
            cin>>a>>b;
            cout<<getAnswer(sumArray,far,a,b)<<"\n";
        }
    }
}