#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
using namespace std;

ll askJudge(int row1,int col1,int row2,int col2){
    int x;
    cout<<1<<" "<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<"\n";
    cin>>x;
    return x;
}

void rowCheck(vector<vector<int>> &vec2d, int row, int ss,int se){
    if(ss>se)return;
    
    int col1 = ss + 1;
    int col2 = se + 1;
    int x = askJudge(row+1,col1,row+1,col2);
    if(x==-1){
        exit(0);
    }
    else if(x==0){
        return;
    }
    else if(x==(se-ss+1)){
        for(int ix=ss;ix<=se;ix++)vec2d[row][ix]=1;
        return;
    }
    else{
        int mid = (ss+se)/2;
        rowCheck(vec2d,row,ss,mid);
        rowCheck(vec2d,row,mid+1,se);
    }
}

int main() {
    ll tests,n,prob;
    cin>>tests;
    while(tests--){
        cin>>n>>prob;
        int x;
        vvi vec2d(n, vi (n, 0));
        
        for(ll i=0;i<n;i++)rowCheck(vec2d,i,0,n-1);
        
        cout<<2<<endl;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++)
                cout<<vec2d[i][j]<<" ";
            cout<<endl;    
        }
        cin>>x;
        if(x==-1)return 0;
    }
    
	return 0;
}
