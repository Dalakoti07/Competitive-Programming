// https://www.codechef.com/viewsolution/35129901
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[21][2][2][11][11][2];
// dp[index][odd][even][last][second_last][flag]
int dig[21];

int solve(int ind,int odd,int even,int last,int second_last,int flag){
    if(dp[ind][odd][even][last][second_last][flag] != -1) return dp[ind][odd][even][last][second_last][flag];
    if(ind == 20){
        if(odd and even) return 1;
        else return 0;
    }
    int res = 0;
    if(flag == 0){
        for(int i = 0; i < dig[ind]; i ++){
            res += solve(ind+1,
                (odd | second_last == i),
                (even | last == i),
                ((last == 10 and i == 0)?10:i),
                (last),
                (1)
                );
        }
        res += solve(ind+1,(odd | second_last == dig[ind]),
                (even | last == dig[ind]),
                ((last == 10 and dig[ind] == 0)?10:dig[ind]),
                (last),
                (0)
                );
    }
    else{
        for(int i = 0; i < 10; i ++){
            res += solve(ind+1,
                (odd | second_last == i),
                (even | last == i),
                ((last == 10 and i == 0)?10:i),
                (last),
                (1)
                );
        }
    }
    return dp[ind][odd][even][last][second_last][flag] = res;
}

int count(int x){
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 11; l++){
                    for(int m = 0; m < 11; m++){
                        for(int n = 0; n < 2; n++){
                            dp[i][j][k][l][m][n] = -1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < 21; i++) dig[i] = 0;
    int cur = 19;
    while(x){
        dig[cur] = x%10;
        x /= 10;
        cur--;
    }
    return solve(0,0,0,10,10,0);
}

signed main(){
    int t; cin >> t;
    while(t --){
        int a,b; cin >> a >> b;
        cout << count(b)-count(a) << endl;
    }
}