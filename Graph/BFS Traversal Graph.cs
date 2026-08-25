//Link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/* Problem : BFS Traversal of Graph
1. You are given a graph in the form of an adjacency list and a source vertex S.
2. You have to perform a BFS traversal of the graph starting from the source vertex S and return the list of vertices in the order they are visited.
3. graph is connected, and source is not given, 
4. hence i consider 0 as source of graph from which BFS starts
*/

//Code : C++

class Solution {
  public:
  
    vector<int> BFSTraverse(vector<vector<int>> &adj, int S)
    {
        int V = adj.size(); // no of vertices
        
        bool visited[V+1] = {false} ; // maintaing visited array
        
        queue<int>q;
        vector<int>res;
        
        q.push(S);
        visited[S] = true;
        
        while(q.empty()==false)
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            
            for(auto v:adj[u])
            {
                if(visited[v]==false)
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        
        return res;
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        
        // here we considering source  = 0 ; 
        // from which BFS starts
        
        vector<int> res = BFSTraverse(adj, 0);
        return res;
        
    }
};