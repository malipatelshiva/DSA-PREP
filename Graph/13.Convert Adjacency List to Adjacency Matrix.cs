//Link : https://www.geeksforgeeks.org/problems/convert-adjacency-list-to-adjacency-matrix/1

//Problem : Given an undirected graph with V vertices and E edges, your task is to convert the given adjacency list 
// representation of the graph into an adjacency matrix representation.

class Solution {
  public:
    vector<vector<int>> adjToMat(vector<vector<int>>& adj) {
        // code here
        int V = adj.size();
        
        vector<vector<int>>adjMat(V,vector<int>(V,0));
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int v = adj[i][j];
                adjMat[i][v] = 1;
            }
        }
       
        return adjMat;
    }
};