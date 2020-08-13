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

void solve(){
    map<char,int> lwa,lwb;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
        lwa[a[i]]++;
    for(int i=0;i<b.size();i++)
        lwb[b[i]]++;
    
    // scenario one that if b has exact same characters that A have, then no matter what A pick B would
    // pick that same char and win at his first turn, making a palindrome of len 2

    // B winning in its first turn
    bool allEqual=true;
    for(auto i:lwa){
        if(lwb[i.first]==0)
            allEqual=false;
    }
    if(allEqual){
        cout<<"B"<<endl;return;}

    // scenario 2 A has played with unique char , and now if B has a unique character, 
    // which A does not posses than its ok, otherwise A would win
    // for example 'x' and if B has no unique char and it has 'f' which is present in A also then 
    // he would do 'xf' and then A would win the game in his second turn
    
    // A winning in its second turn
    bool hasUnique=false;
    for(auto i:lwb){
        if(lwa[i.first]==0)
            hasUnique=true;
    }
    if(!hasUnique){
        cout<<"A"<<endl;return;}

    // scenario 3, if A contains a char is unique and count is >=2 than it would win no matter what
    
    // A winning in its second turn
    for(auto i:lwa){
        char letter=i.first;
        int count=i.second;
        if(lwb[letter]==0 and count>=2){
            cout<<"A"<<endl;
            return;
        }
    }


    // by now we have string of length 3 , which contain atleast 2 unique char, and a plaindrome can not have
    // other scenario
    // more than 1 unique chars thus no palindrome can be found thus B wins, or if some palindrome gets made than 
    // that would be of B (think about it )
    cout<<"B"<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}