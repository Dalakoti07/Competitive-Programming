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
	int p1,l1,p2,l2,read_speed,write_speed,time;
  cin>>p1>>l1>>p2>>l2>>read_speed>>write_speed>>time;

  int timeToReadFirstBook;
  timeToReadFirstBook=(l1*p1)/read_speed;

  if(timeToReadFirstBook>time){
    // means book is not finished
    if((time*read_speed)%l1 ==0)
      cout<<"READ "<<(time*read_speed)/l1<<" "<<l1;
    else
      cout<<"READ "<<(time*read_speed)/l1<<" "<<(time*read_speed)%l1;
  }else{
    if(timeToReadFirstBook==time){
      cout<<"WRITE 0 0";
    }else{
      // pagesToBeWritten=min(p2*l2,(timeToReadFirstBook-time)*);
      // cout<<"time rem "<<time-timeToReadFirstBook;
      if(((time-timeToReadFirstBook)*write_speed)%l2==0)
        cout<<"WRITE "<<((time-timeToReadFirstBook)*write_speed)/l2<<" "<<l2;
      else
        cout<<"WRITE "<<((time-timeToReadFirstBook)*write_speed)/l2<<" "<<((time-timeToReadFirstBook)*write_speed)%l2;
    }
  }
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}