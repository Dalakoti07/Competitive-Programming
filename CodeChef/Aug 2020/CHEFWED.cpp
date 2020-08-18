#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
int n,k,x;
vector<int> arr(1000);
int memo[1001][1001],freq[1001][1001];
// freq[i][j] store the frequency of j till index i
int rec(int i,int j){
    if(j>n) return 0;
    if(i==n) return 0;
    if(i==j) return k;
    if(memo[i][j]!=-1) return memo[i][j];

    int ans=INT_MAX;
    // one way is put all the people in one table
    map<int,int> uniqueElems; // pair<elem,with last index>
    for(int a=i;a<=j;a++)
        uniqueElems[arr[a]]=a;
    int cost=0;
    for(auto m: uniqueElems){
        int key=m.first,val=m.second;
        int f;
        if(i>0)
            f=freq[key][val]-freq[key][i-1];
        else{
            f=freq[key][val]-0;
        }
        if(f!=1)
            cost+=f;
    }
    cost+=k;
    ans=min(ans,cost);

    // other way break table into various sub-tables
    for(int x=i;x<j;x++){
        ans=min(ans,rec(i,x)+rec(x+1,j));
    }
    memo[i][j]=ans;
    return ans;
}

void solve(){
    // the conjecture is either all in one table or all in seperate table
    
    // memset(freq,0,sizeof(freq));
    cin>>n>>k;
    memset(memo,-1,sizeof(memo));
    memset(freq,0,sizeof(freq));
    FOR(i,n){
        // freq[i][j] store the frequency of j till index i
        cin>>arr[i];
    }

    // make freq array in n^2 time, print the freq table
    // freq[arr[i]][i]=freq[arr[i]][i-1]+1;
    set<int> elemsPutted;

    // n^2 square 
    for(int i=0;i<n;i++){
        if(elemsPutted.find(arr[i])==elemsPutted.end()){
            freq[arr[i]][i]=1;
            for(int x=i+1;x<n;x++){
                if(arr[x]==arr[i])
                    freq[arr[i]][x]=freq[arr[i]][x-1]+1;
                else
                    freq[arr[i]][x]=freq[arr[i]][x-1];
            }
            elemsPutted.insert(arr[i]);
        }
    }

    // for(int i=1;i<=n;i++,cout<<endl)
    //     for(int j=0;j<=n;j++)
    //         cout<<freq[i][j]<<" ";

    if(k==1){
        set<int> currTable;
        currTable.insert(arr[0]);
        int tableCount=0;
        for(int i=1;i<n;i++){
            if(currTable.find(arr[i])!=currTable.end()){
                tableCount++;
                currTable.clear();
                currTable.insert(arr[i]);
            }else{
                currTable.insert(arr[i]);
            }
        }
        tableCount++;
        int oneWay=tableCount*k;
        cout<<oneWay<<endl;
    }else{
        // greedy fails thus dp or rec
        // rec find the cost of placing all people from i to j in one table
        
        cout<<rec(0,n-1)<<endl;
    }
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}