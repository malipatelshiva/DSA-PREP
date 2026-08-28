//Link : https://www.geeksforgeeks.org/problems/count-number-of-edges-in-an-undirected-graph/1

//code :


class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        // code here
        
        
        //iam thinking this way,
        // if there is an edge from u to v, then it will added to both adj[u] ->v and adj[v]->u in an undirected graph
        // that means, in adjacency list representation, edges are stored in both ways, which tells each edge is consider 2 times 
        // so overall total no of edges will be equal to sum of size of each adj list nd then take half of it
        
        int sum = 0;
        
        for(auto x: adj)
        {
            sum = sum + x.size();
        }
        
        return sum/2;
    }
};