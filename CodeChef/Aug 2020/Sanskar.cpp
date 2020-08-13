#include <bits/stdc++.h>
using namespace std ;

#define FOR(i,a,b) for(int i= (int)a; i< (int)b; ++i)
#define REP(i,n) FOR(i,0,n)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define mod 1000000007

LL arr[22];
bool dp[10][1LL << 22];

void solve(int N, int K) {
   LL sum = 0;
   for(int i = 0; i < N; i++){
      sum += arr[i];
   }
   if((sum % K != 0) || (N<K) ){
      puts("no");
      return;
   }
   if(sum == 0) {
      puts("yes");
      return;
   }
   LL X = sum / K;
   LL maxBit = (1LL << N);

   fill(dp, 0);
   dp[0][0] = true;

   REP(i, K) {
      for(LL mask=0; mask<maxBit; mask++) {
         if(!dp[i][mask]) continue;
         sum = 0;
         REP(j, N) {
            if(!(mask & (1LL << j))) continue;
            sum += arr[j];
         }
         sum -= i * X;
         REP(j, N) {
            if(mask & (1LL << j)) continue;
            if(sum + arr[j] == X) {
               dp[i + 1][mask | (1LL << j)] = true;
            }else if(sum + arr[j] < X) {
               dp[i][mask | (1LL << j)] = true;
            }
        }
      }
   }
   puts(dp[K][maxBit - 1] ? "yes" : "no");
}

int main(){
   int T;
   cin >> T;
   while(T--){
      int n,k;
      scanf("%d %d", &n, &k);
      REP(i,n) {
         scanf("%Ld", &arr[i]);
      }
      solve(n,k);
   }
}