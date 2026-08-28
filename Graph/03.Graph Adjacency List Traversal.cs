//Link : https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
/* Problem : Print Adjacency List


1. You are given a graph in the form of an adjacency list.
2. You have to print the adjacency list of the graph.  */  
  
class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        
        vector<vector<int>>adj(V);
        
        for( auto x:edges)
        {
            int u = x.first;
            int v = x.second;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};