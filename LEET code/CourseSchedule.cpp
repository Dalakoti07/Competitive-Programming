class Solution {
public:
    bool containsCycle(vector<vector<int>>& graph,int currentNode,int n,vector<bool>& SoFarSeen){
        if(SoFarSeen[currentNode]==true) return true;
        else SoFarSeen[currentNode]=true;

        // traverse all of its children 
        for(int i=0;i<n;i++){
            if(graph[currentNode][i]==1){
                if(containsCycle(graph,i,n,SoFarSeen)) return true;
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = vector<vector<int>> (numCourses,vector<int>(numCourses,0));
        int bound = prerequisites.size();
        for(int i=0;i<bound;i++){
            graph[prerequisites[i][0]][prerequisites[i][1]]=1;
        }
        // traverse the graph
        vector<bool> SoFarSeen=vector<bool>(numCourses,false);
        return ! containsCycle(graph,0,numCourses,SoFarSeen);
    }
};