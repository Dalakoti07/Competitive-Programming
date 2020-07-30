
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

const int MOD = 1000000007;


pair<pair<int,int>,pair<int,int> > multiply(pair<pair<int,int>,pair<int,int> > A,pair<pair<int,int>,pair<int,int> > B){
    pair<pair<int,int>,pair<int,int> > res;
    res.F.F = (A.F.F*B.F.F+A.F.S*B.S.F)%MOD;
    res.F.S = (A.F.F*B.F.S+A.F.S*B.S.S)%MOD;
    res.S.F = (A.S.F*B.F.F+A.S.S*B.S.F)%MOD;
    res.S.S = (A.S.F*B.F.S+A.S.S*B.S.S)%MOD;
    return res;
}

pair<pair<int,int>,pair<int,int> > power(pair<pair<int,int>,pair<int,int> > A,int n){
    if(n == 1) return A;
    if(n%2 == 1){
        return multiply(power(A,n-1),A);
    }
    else{
        pair<pair<int,int>,pair<int,int> > submatrix = power(A,n/2);
        return multiply(submatrix,submatrix);
    }
}

int n,m;

signed main(){
    int t; cin >> t;
    while(t --){
        cin >> n >> m;
        m %= MOD;
        if(n == 1){
            cout << m << endl;
            continue;
        }
        if(n == 2){
            cout << (m*m)%MOD << endl;
            continue;
        }
        pair<pair<int,int>,pair<int,int> > matrix;
        matrix.F.F = (m-1+MOD)%MOD;
        matrix.F.S = (m-1+MOD)%MOD;
        matrix.S.F = 1;
        matrix.S.S = 0;
        pair<pair<int,int>,pair<int,int> > powered_matrix = power(matrix,n-1);
        int ans = (powered_matrix.S.F*m+powered_matrix.S.S)%MOD;
        cout << (ans*m)%MOD << endl;
    }
}