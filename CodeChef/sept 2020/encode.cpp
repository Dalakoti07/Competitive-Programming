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

// code from below

void solve(){
    string str;
    getline(cin, str); 
    stringstream ss(str);
    // first step remove space
    string newS="",word;
    while (ss >> word) 
        newS=newS+word;
    int length=newS.length();
    int w=ceil(sqrt(length));
    // step 4
    vector<string> vecString;
    int i=0;
    for(;i<length;){
        vecString.push_back( newS.substr(i,w));
        i+=w;
    }
    if(i<length){
        vecString.push_back(newS.substr(i,w));
    }

    // for(auto s:vecString)
    //     cout<<s<<" ";
    // cout<<endl;
    // last step
    vector<string> answers;
    for(int i=0;i<vecString[0].size();i++){
        string temp="";
        for(int j=0;j<vecString.size();j++){
            if(vecString.size()>0){
                temp+=vecString[j][i];
                // remove the character
                // vecString[i]=vecString[i].substr(1);
            }
        }
        answers.push_back(temp);
    }

    for(auto s:answers)
        cout<<s<<" ";
    cout<<endl;
}

int main(){
    int t=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}