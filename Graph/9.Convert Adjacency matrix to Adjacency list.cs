//Link : https://www.geeksforgeeks.org/problems/convert-adjacency-matrix-to-adjacency-list/1

class Solution {
  public:
    vector<vector<int>> matToAdj(vector<vector<int>>& mat) {
        // code here
        
        int V= mat.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(mat[i][j]!=0)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        return adj;
    }
};