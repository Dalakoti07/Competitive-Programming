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

// it was greedy where we could generate answer in two ways and thus we picked a best answer from both options
string returnSmallerLex(string oneWay,string secondWay){
    bool oneIsCorrect=true;
    for(int i=0;i<oneWay.size();i++){
        if(oneWay[i]!=secondWay[i])
            return oneWay[i]>secondWay[i] ? secondWay : oneWay;
    }
    return oneWay;
}

void solve(){
    map<char,int> charsInString,charsInPatterns;
	string str,patt;
    cin>>str>>patt;
    for(char c: str){
        charsInString[c]++;
    }
    for(char c: patt){
        charsInPatterns[c]++;
        charsInString[c]--;
    }

    char firstCharOfPattern=patt[0];
    string ans=patt,leftAnsOne="",leftAnsTwo="",rightAnsOne="",rightAnsTwo="";
    string oneWay,secondWay;
    // think once again considering the examples and how it solved the problem
    // we have two choices and thus we take both choices and compare the choices, and get best results

    map<char,int> copyOfMap=charsInString;
    // forming the answer string for wayOne
    for(auto m:charsInString){
        if(m.first <firstCharOfPattern){
            int c=  m.second;
            while(c){
                leftAnsOne+=m.first;
                c--;
            }
            charsInString[m.first]=0;
        }
    }// right ans for way one
    for(auto m:charsInString){
        if(m.first >=firstCharOfPattern){
            int c=  m.second;
            while(c){
                rightAnsOne+=m.first;
                c--;
            }
            charsInString[m.first]=0;
        }
    }
    oneWay=leftAnsOne+ patt + rightAnsOne;

    // forming answer string for wayTwo
    for(auto m: copyOfMap){
        if(m.first <=firstCharOfPattern){
            int c=m.second;
            while(c){
                leftAnsTwo+=m.first;
                c--;
            }
            copyOfMap[m.first]=0;
        }
    }// right ans for way two
    for(auto m:copyOfMap){
        if(m.first >firstCharOfPattern){
            int c=  m.second;
            while(c){
                rightAnsTwo+=m.first;
                c--;
            }
            copyOfMap[m.first]=0;
        }
    }
    secondWay=leftAnsTwo+patt+rightAnsTwo;

    // asserting length
    assert(oneWay.size()==str.size());
    assert(secondWay.size()==str.size());

    // pick the best from both answers
    ans=returnSmallerLex(oneWay,secondWay);
    cout<<ans<<endl;
    assert(ans.size()==str.size());
}

int main(){
    // init();
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}