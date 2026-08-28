//Link :https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//Difficulty : Medium
//Company asked : Flipkart Amazon Microsoft Samsung MakeMyTrip Oracle Adobe


class Solution {
  public:
  
    bool DFSDetectCycle(vector<vector<int>>&adj,int u, int parent, vector<bool>&visited)
    {
        visited[u] = true;
        
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                // v is adjacent of u, it is not visited
                // then call it's DFS
                
                if(DFSDetectCycle(adj,v,u,visited)==true)
                {
                    return true;
                }
            }
            else
            {
                // if true, if check it is not same as parent
                if(v!=parent)
                {
                    return true;
                }
            }
            
        }
        return false;
    
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        // 1. build adjacency list
        // 2. using DFS Traversal, we can solve this problem
        // 3. by checking visited[vertex] true, if any vertex is visiting for first
        // 4. we make it as true, if we visting for second time, will see it's value as True.
        // 5. Then, we can simply say, vertex is visited already, hence there is cycle
        // 6. ** we should handle one important corner case, not considering parent as visited vertex, if DFS call is happenining through same vertex
        // let's say 0------1 
        
        /*
            0 is turned as visited for the first,
            DFS for 1 is called, and turned True, as 0 is adjacent of 1, next call will be DFS(0)
            but here comes main thing, as 0 is already visited and 1 just came from 0 ( 0 is processed before 1) 
            so considering it as cycle will lead to wrong answer, 
            
            hence, we handle this case by maintaining parent variable
            
        */
        
        //creating adjacency list
        
        vector<vector<int>>adjList(V);
        for(auto x: edges)
        {
            int u = x[0];
            int v = x[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
        }
        
        vector<bool>visited(V);
        
        for(int i=0;i<V;i++)
        {
            //at first parent = -1, as we dont have any parent at first,
            //i is the starting vertex from which we starting DFS Call
            
            if(visited[i]==false)
            {
                if(DFSDetectCycle(adjList,i,-1,visited) == true)
                {
                    return true;
                }
            }
      
        }
        
        return false;
    }
};