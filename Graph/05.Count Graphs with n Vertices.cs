//Link : https://www.geeksforgeeks.org/problems/graph-and-vertices/1

//Problem : Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.



class Solution {
  public:
    long long count(int n) {
        // code here
        
        /*
        
        For an undirected graph with n vertices, assuming:

        No self-loops (i → i is not allowed)
        At most one edge between any pair of vertices
        The graph can be disconnected

        the answer is: 2^ (n*(n-1))/2;
        
        How : In an undirected graph, an edge can exist between every pair of distinct vertices.

              Number of possible pairs : (n*(n-1))/2; // these many no of edges possible for undirected graph,
              
              For each edge between two vertices , we have two options
              
              1. Edge exists
              2. Edge does not exist
              
              hence, answer will  be : 2^ ( (n*(n-1)/2) )
              
              
        
        Note : For Directed Graph : it is   2^ ( (n*(n-1)) )
        
                because total no of edges possible for a graph with vertices n is (n*(n-1));
        */

        
        long long edges = 1LL * n * (n - 1) / 2;
        return 1LL << edges;
    }
};