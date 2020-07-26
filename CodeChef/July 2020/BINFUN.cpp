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
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

string decimalToBinary(int n){
    string s = bitset<32> (n).to_string(); 
    
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0";
}

ll binaryConcat(int x,int y){
    string a=decimalToBinary(x);
    string b=decimalToBinary(y);
    // cout<<"x: "<<x<<" :"<<a<<" y: "<<y<<" :"<<b<<endl;

    string aPlusb=a+b;
    string bPlusa=b+a;
    // cout<<"\naPlusb : "<<aPlusb<< "bPlusa : "<<bPlusa;
    ll num1=stoll(aPlusb, 0, 2);
    ll num2=stoll(bPlusa,0,2);
    // cout<<" \nint of apb: "<<num1<<" bpa: "<<num2;
    return abs(num1-num2);
}

int solve(){
	int n;
    cin>>n;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    ll Max=INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            Max=max(Max,binaryConcat(arr[i],arr[j]));
        }
    }
    cout<<Max<<endl;
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