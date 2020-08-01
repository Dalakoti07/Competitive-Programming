

#include<bits/stdc++.h>

using namespace std;

typedef long double ll;

const int MX = (1<<20);


int main(){
    int T;
    cin>>T;
    while(T--){
        int n , z1 , z2;
        cin>>n>>z1>>z2;
        set < int > S;
        for(int j = 1 ; j <= n ; j++){
            int x;
            cin>>x;
            S.insert(x);
        }
        // if game can finished in one go
        if(S.count(z1) || S.count(z2) || S.count(-z1) || S.count(-z2)){
            puts("1");
            continue;
        }
        bool second = 1;
        // if 1 is at dead end
        for(auto x : S){
            second &= (S.count(z1 - x) || S.count(z2 - x) || S.count(x - z1) || S.count(x - z2));
            x = -x;
            second &= (S.count(z1 - x) || S.count(z2 - x) || S.count(x - z1) || S.count(x - z2));
        }
        if(second){
            puts("2");
            continue;
        }
        // players are playing optimally which means as per question if they cannot win the game they will try to draw it
        puts("0");
    }
}