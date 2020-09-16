#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// mother of all adhocs, implementation is king

void solve(){
	int n,m;
    cin>>n>>m;
    // stores the rating of ith person in jth match
    vector<vector<int>> rating(n+1,vector<int>(m+1));
    // store the match in which person achieved the max rating
    vector<int> max_rating_reached(n+1);
    // stores the ranking of ith person in jth match
    vector<vector<int>> ranking(n+1,vector<int>(m+1));
    vector<int> best_rank_reached(n+1);

    for(int i=1;i<=n;i++)
        cin>>rating[i][0]; // rating before all matches 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int delta;
            cin>>delta;
            rating[i][j]=rating[i][j-1] +delta;
        }
        // calculate the maxrating reached for each person
        // one more observation that we are processsing while reading its ok, this saves us time as below loop is just outer loop
        // for(int i=1;i<=n;i++){
        // }
        int maxRating=INT_MIN,idx=-1;
        for(int j=1;j<=m;j++){
            if(rating[i][j]>maxRating){
                maxRating=rating[i][j];
                idx=j;
            }
        }
        max_rating_reached[i]=idx;
    }

    // calculate the ranking of all i player in each j match and store them
    for(int j=1;j<=m;j++){
        vector<pair<int,int>> rating_id(n);
        for(int i=1;i<=n;i++){
            rating_id[i-1]={rating[i][j],i};
        }
        sort(rating_id.rbegin(),rating_id.rend()); //sort in desc order
        int curr_rank=1,next_rank=2,prev_ranking=rating_id[0].first;
        // another master stroke
        for(int i=0;i<n;i++){
            if(prev_ranking==rating_id[i].first){
                ranking[rating_id[i].second][j]=curr_rank;// same people can have similar rank but next rank would increment
                next_rank++;
            }else{
                curr_rank=next_rank;
                next_rank++;
                ranking[rating_id[i].second][j]=curr_rank;
                prev_ranking=rating_id[i].first;
            }
        }
    }
    // calculate best ranking
    for(int i=1;i<=n;i++){
        int bestRanking=INT_MAX,idx=-1;
        for(int j=1;j<=m;j++){
            if(bestRanking>ranking[i][j]){
                bestRanking=ranking[i][j];
                idx=j;
            }
        }
        best_rank_reached[i]=idx;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(best_rank_reached[i]!=max_rating_reached[i])
            ans++;
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}