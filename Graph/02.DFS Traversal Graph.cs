//Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1\


/* Problem : DFS Traversal of Graph
1. You are given a graph in the form of an adjacency list and a source vertex S.
2. You have to perform a DFS traversal of the graph starting from the source vertex S and return the list of vertices in the order they are visited.
3. graph is connected, and source is not given, 
4. hence i consider 0 as source of graph from which DFS starts
*/

// Code : C++


class Solution {
  public:
  
    void DFSTraverse(vector<vector<int>>&adj,int S, vector<bool>&visited,vector<int>&res)
    {
        
        visited[S] = true;
        res.push_back(S);
        
        for(auto v : adj[S])
        {
            if(visited[v] == false)
            {
                DFSTraverse(adj,v,visited, res);
            }
        }
        
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        
        // we will consider 0 as source of graph 
        // from which DFS starts
        
        int V = adj.size();
        vector<bool>visited(V+1,false);
        vector<int>res;
        DFSTraverse(adj,0,visited,res);
        return res;
        
    }
};