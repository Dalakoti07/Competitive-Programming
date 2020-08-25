class Solution {
public:
    bool dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, stack<int>& coursesOrder){
        visited[v]=true;
        recStack[v]=true;
        for(int child: graph[v]){
            if(recStack[child])
                return false;
            if(visited[child]==false){
                if(dfs(child,graph,visited,recStack,coursesOrder)==false)
                    return false;
            }
        }
        coursesOrder.push(v);
        recStack[v]=false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        int bound = prerequisites.size();
        for(int i=0;i<bound;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // traverse the graph and find topological sort
        stack<int> coursesOrder;
        vector<bool> visited(numCourses);// for visited node
        vector<bool> recStack(numCourses);// for rec stack to check if there is back-edge
        for(int i=0;i<numCourses;i++){
            visited[i]=false;
        }
        // pick any non-visited vertex;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                if(dfs(i,graph,visited,recStack,coursesOrder)==false){// means there is backedge
                    return ans;
                }
            }
        }
        // why this check, ? just a sanity check
        if(coursesOrder.size()!=numCourses)
            return ans;
        while(coursesOrder.size()!=0){
            ans.push_back(coursesOrder.top());
            coursesOrder.pop();
        }
        return ans;
    }
};