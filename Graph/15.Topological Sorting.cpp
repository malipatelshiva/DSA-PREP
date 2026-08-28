//Topological Sort
//Link :https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        
        //1. create adjacency list
        vector<vector<int>>adjList(V);
        vector<int>indegree(V,0);
        
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];    
                
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int>res;
        
        while(q.empty()==false)
        {
            
            int u = q.front();
            q.pop();
            
            res.push_back(u);
            
            for(auto v:adjList[u])
            {
                if(--indegree[v]==0)
                {
                    q.push(v);
                }
            }
            
        }
        
        return res;
    }
};