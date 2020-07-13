#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> fibNumbers(61);

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// fibonacci are repetitive after 60 when mod with 10 thus we making only arr of 60
void precompute(){
	fibNumbers[0] = 0; fibNumbers[1] = 1;
	for (int i = 2; i < 61; i++) {
		fibNumbers[i] = (fibNumbers[i - 1] + fibNumbers[i - 2]) % 10;
	}
}

void solve(){
    long long n;
    cin>>n;
    int c = 0;
    while ( n >>= 1) {
        c++;
    }
    int d = (int(pow(2, c)) - 1) % 60;
    cout << fibNumbers[d]%10 << endl;
}

int main(){
    // init();
    int t;
    cin>>t;
    precompute();
    while(t--){
        solve();
    }
}