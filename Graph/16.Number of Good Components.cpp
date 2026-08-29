//Link : https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1
//Leetcode : https://leetcode.com/problems/count-the-number-of-complete-components/description/

/*

    1. What is the core idea?

For every connected component, you:

Find all vertices belonging to that component using DFS.
Store those vertices in temp.
Check whether every vertex has exactly component_size - 1 neighbors.
If yes → that component is complete.
Count it.

The key observation is:

If a component has k vertices, then in a complete graph, every vertex must be connected to exactly k - 1 other vertices.


*/

GFG :

class Solution {
  public:
    
    void DFS(vector<vector<int>>&adj,int s, vector<bool>&visited, vector<int>&temp)
    {
        
        visited[s] = true;
        
        temp.push_back(s);
        
        for(auto u:adj[s])
        {
            if(visited[u]==false)
            {
                DFS(adj,u,visited,temp);
            }
        }
        
    }
    
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) 
    {
    
        //building adj list;
        vector<vector<int>>adj(v+1);
        
        for(int i=0;i<e;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //we need a visited a array/vector
        
        vector<bool>visited(v+1,false);
        
        int ans = 0;
        
        for(int i=1;i<v+1;i++)
        {
            if(visited[i]==false)
            {
                
                vector<int>temp;
                
                DFS(adj,i,visited,temp);
                
                //we check in temp vector
                bool flag = false;
                
                for(int i=0;i<temp.size();i++)
                {
                    
                    if(adj[temp[i]].size()!=temp.size()-1)
                    {
                        flag = true;
                        break;
                    }
                    
                }
                if(flag == false )
                {
                    ans++;
                }
                
            }
            
            
        }
        return ans;
        
    }
};



//Leetocde : 


class Solution {
public:

    void DFS(vector<vector<int>>&adj,int s, vector<bool>&visited, vector<int>&temp)
    {
        
        visited[s] = true;
        
        temp.push_back(s);
        
        for(auto u:adj[s])
        {
            if(visited[u]==false)
            {
                DFS(adj,u,visited,temp);
            }
        }
        
    }

    int countCompleteComponents(int v, vector<vector<int>>& edges) 
    {

         //building adj list;
        vector<vector<int>>adj(v);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //we need a visited a array/vector
        
        vector<bool>visited(v,false);
        
        int ans = 0;
        
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                
                vector<int>temp;
                
                DFS(adj,i,visited,temp);
                
                //we check in temp vector
                bool flag = false;
                
                for(int i=0;i<temp.size();i++)
                {
                    
                    if(adj[temp[i]].size()!=temp.size()-1)
                    {
                        flag = true;
                        break;
                    }
                    
                }
                if(flag == false )
                {
                    ans++;
                }
                
            }
            
            
        }
        return ans;
        
    }
};

