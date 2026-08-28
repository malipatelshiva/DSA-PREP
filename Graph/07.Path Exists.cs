//Link : https://practice.geeksforgeeks.org/problems/path-exists/1


//Company Asked : NPCI

class Solution {
  public:
  
    bool BFSTraversal(vector<vector<int>>&adj,int V,int src,int dest)
    {
        vector<bool>visited(V,false);
        queue<int>q;
        
        q.push(src);
        visited[src] = true;
        
        while(q.empty()==false)
        {
            int u = q.front();
            q.pop();
            
            // print(u) for BFS traversal values
            
            for(auto v:adj[u])
            {
                if(visited[v]==false)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
            
        }
        
        // if there is a path between src to dest, then would have turned to True in visited array
        // if visited[dest] is false means, there was no path exists from src to dest;
        
        return visited[dest];
        
    }
    bool checkPath(int V, vector<vector<int>>& edges, int src, int dest) {
        // Code here
        
        // I will do BFS here,
        
        // create adjacenty list first
        
        vector<vector<int>>adj(V);
        
        for(auto x:edges)
        {   
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // call BFS
        return BFSTraversal(adj,V,src,dest);
    }
};
