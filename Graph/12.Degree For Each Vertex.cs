//Link : https://www.geeksforgeeks.org/problems/degree-of-each-vertices-in-a-graph/1


class Solution {
  public:
    vector<vector<int>> findInOutDegree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V,0);
        vector<int>outdegree(V,0);
        
        for(auto x:edges)
        {
            int u = x[0];
            int v = x[1];
            
            outdegree[u]++;
            indegree[v]++;
        }
        
        // V vertices, each row contains [in-degree, out-degree]
        vector<vector<int>> res(V, vector<int>(2, 0));
        
        for(int i=0;i<V;i++)
        {
            res[i][0] = indegree[i];
            res[i][1] = outdegree[i];
        }
        return res;
    }
};