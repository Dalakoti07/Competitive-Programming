#include <bits/stdc++.h>
using namespace std;

// rather than making 8 functions which return true/false if possible 
// we can make 2 arrays which tells 8 directios in which we can move 

// so here we have better implementation
int dirsx[]={1,-1,0,0,1,-1,-1,1};
int dirsy[]={0,0,1,-1,1,-1,1,-1};

bool isPossible(char** grid,int n,int m,int ip,int jp,string target){
    int x=ip,y=jp,len=target.length();
    // traverse in all 8 dirs
    for(int i=0;i<8;i++){
        x=ip+dirsx[i];
        y=jp+dirsy[i];
        int j;
        for(j=1;j<len;j++){
    
            if(x>=n or y>=m or x<0 or y<0)
                break;
            if(grid[x][y]!=target[j])
                break;
            //cout<<"finding "<<target[j]<<" at ["<<x<<" : "<<y<<"]\n";
            x+=dirsx[j];
            y+=dirsy[j];
        }
        if(j==len)
            return true;
    }
    return false;
}

vector<pair<int,int>> solve(char** grid,int n,int m,string target){
    vector<pair<int,int>> results;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==target[0]){
                if(isPossible(grid,n,m,i,j,target))
                    results.push_back({i,j});
            }
        }
    }
    return results;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    char** grid= new char*[n];
	    for(int i=0;i<n;i++)
	        grid[i]= new char[m];
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++)
	            cin>>grid[i][j];
	    string target;
	    cin>>target;
	    vector<pair<int,int>> results=solve(grid,n,m,target);
        if(results.size()==0){
            cout<<-1<<endl;
        }else{
            for(pair<int,int> p: results){
                cout<<p.first<<" "<<p.second<<", ";
            }
            cout<<endl;
        }
	}
	return 0;
}