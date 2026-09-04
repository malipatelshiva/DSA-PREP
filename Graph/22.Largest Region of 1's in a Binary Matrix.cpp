//Link GFG : https://www.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

/*Notes
Same like problem 21, max area of island, but here we have to find the length of largest region of 1's 
instead of counting the number of islands. 
The length of region is defined as the number of cells with value 1 that are connected 8-directionally (horizontal, vertical or diagonal). 
We can use DFS to traverse the grid and calculate the length of each region, keeping track of the maximum length found.
*/


class Solution {
  public:
  

       bool isValid(vector<vector<int>>& grid,int i,int j,int m,int n)
        {
            if( i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void DFSRec(vector<vector<int>>& grid,int i,int j,int m,int n,int &count)
        {
            grid[i][j] = 0;
            count++;
            if(isValid(grid,i+1,j,m,n))
                DFSRec(grid,i+1,j,m,n,count);
            if(isValid(grid,i-1,j,m,n))
                DFSRec(grid,i-1,j,m,n,count);
            if(isValid(grid,i,j+1,m,n))
                DFSRec(grid,i,j+1,m,n,count);
            if(isValid(grid,i,j-1,m,n))
                DFSRec(grid,i,j-1,m,n,count);
                
            if(isValid(grid,i+1,j+1,m,n))
                DFSRec(grid,i+1,j+1,m,n,count);

            if(isValid(grid,i+1,j-1,m,n))
                DFSRec(grid,i+1,j-1,m,n,count);

            if(isValid(grid,i-1,j+1,m,n))
                DFSRec(grid,i-1,j+1,m,n,count);

            if(isValid(grid,i-1,j-1,m,n))
                DFSRec(grid,i-1,j-1,m,n,count);

        }

    int largestRegion(vector<vector<int>>& grid) {
        // Code here
        
            int m = grid.size();
            int n = grid[0].size();

            int result = 0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {   
                    int count = 0;
                    if(grid[i][j]==1)
                    {
                        DFSRec(grid,i,j,m,n,count);
                        result = max(result,count);
                    }

                }
            }
            return result;

        
    }

};