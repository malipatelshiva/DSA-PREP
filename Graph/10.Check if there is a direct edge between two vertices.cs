//Link : https://www.geeksforgeeks.org/problems/check-if-there-is-a-direct-edge-between-two-vertices/1

// just traverse the adjacency list of u and check if v is present or not

class Solution {
  public:
    bool checkEdge(vector<vector<int>>& adj, int u, int v) {
        // code here
        
        int size = adj[u].size();
        for(auto x : adj[u])
        {
            if(x ==v)
            {
                return true;
            }
        }
        return false;
    }
    
};