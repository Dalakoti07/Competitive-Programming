class Solution {
public:
    bool checkCycle(int v,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& recStack){
        visited[v]=true;
        recStack[v]=true;
        for(int child: graph[v]){
            if(recStack[child]) // if it has a child which is already in rec stack than 
            // we have a back edge and thus we have got the cycle
                return true;
            if(!visited[child] and checkCycle(child,graph,visited,recStack)) // if node is not visted than explore it
                // if it tells there is cycle than we have cycle, return true, to signify cycle
                return true;
        }
        recStack[v]=false;// remove this node from recstack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
//         the way u make graph does not matter, cycle wont change
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses);
        vector<bool> recStack(numCourses);
        for(int i=0;i<numCourses;i++){
            visited[i]=false;
            recStack[i]=false;
        }

        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                if(checkCycle(i,graph,visited,recStack))
                    return false;
            }
        }
        return true;
    }
};