#include <vector>
using namespace std;

bool isNodeInCycle(int node,vector<vector<int>>& edges
	,vector<bool>& visited,vector<bool>& currentlyInStack);

bool cycleInGraph(vector<vector<int>> edges) {
	int nodes=edges.size();
	vector<bool> visited(nodes,false);
	vector<bool> currentlyInStack(nodes,false);
	
	for(int node=0;node<nodes;node++){
		if(visited[node])
			continue;
		bool containsCycle=isNodeInCycle(node,edges,visited,currentlyInStack);
		if(containsCycle)
			return true;
	}
	
  return false;
}

bool isNodeInCycle(int node,vector<vector<int>>& edges
	,vector<bool>& visited,vector<bool>& currentlyInStack){
	visited[node]=true;
	currentlyInStack[node]=true;
	
	auto neighbours=edges[node];
	for(auto neighbour:neighbours){
		if(!visited[neighbour]){
			bool containsCycle=isNodeInCycle(neighbour,edges,visited,currentlyInStack);
			if(containsCycle)
				return true;
		}else if(currentlyInStack[neighbour]){
			return true;
		}
	}
	currentlyInStack[node]=false;
	return false;
}
