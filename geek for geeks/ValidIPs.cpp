#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7
#define deb(x) cout<< #x << " = "<<x<<endl;

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

bool isValid(string s){
    vector<string> numbers;
    int n=s.length();
    string num="";
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            num+=s[i];
            numbers.push_back(num);
            num="";
        }else{
            num+=s[i];
        }
    }
    numbers.push_back(num);
    // check numbers
    for(string a:numbers){
        cout<<a<<" ";
        if(a.size()>3 or stoi(a)<0 or stoi(a)>255)
            return false;
        if(a.size()>1 and stoi(a)==0)
            return false;
        if(a.size()>1 and stoi(a)!=0 and a[0]=='0')
            return false;
    }
    return true;
}

// code from below
// https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/
void solve(){
	string s;
    cin>>s;
    int n =s.length();
    string ip=s;
    vector<string> correctIps;
    // using brute force to put three dots at correct places
    for(int i=1;i<n-2;i++){// n-2 because after this two more digits would come 
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                ip=ip.substr(0,k)+"."+ip.substr(k,n-k+2);
                ip=ip.substr(0,j)+"."+ip.substr(j,n-j+3);// +3 because as dot was added in previous line
                ip=ip.substr(0,i)+"."+ip.substr(i,n-i+4);
                if(isValid(ip)){
                    correctIps.push_back(ip);
                }
                ip=s;
            }
        }
    }
    for(string ci:correctIps)
        cout<<ci<<" ";
    cout<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}