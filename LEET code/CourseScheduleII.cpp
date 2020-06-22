class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        int bound = prerequisites.size();
        for(int i=0;i<bound;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // traverse the graph and find topological sort
        
    }
};