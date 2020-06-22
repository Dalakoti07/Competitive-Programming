class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> graph = vector<vector<int>>(N+1,vector<int>(N+1,0));
        int bound =trust.size();
        // fill the graph
        for(int i=0;i<bound;i++){
            graph[trust[i][1]][trust[i][0]]=1;
        }
        // find ans, traverse the graph and see results
        for(int i=1;i<=N;i++){
            // check if i is judge
            int j;
            if(graph[i][i]==1) continue;
            for(j=1;j<=N;j++){
                if(graph[j][i]==1) break;
                if(graph[i][j]==0 and j!=i) break;
            }
            if(j==N+1) return i;
        }
        return -1;
    }
};