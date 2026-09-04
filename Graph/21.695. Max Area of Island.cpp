//Link : https://leetcode.com/problems/max-area-of-island/description/

/*
Note : This problem is similar to Number of Islands problem but 
//here we have to find the maximum area of island instead of counting the number of islands. The area of island is defined as the number of cells with value 1 that are connected 4-directionally (horizontal or vertical). We can use DFS to traverse the grid and calculate the area of each island, keeping track of the maximum area found.
 one more point : we passing count by reference in DFSRec function because we want to keep track of the area of the current island as we traverse it. 
 By passing count by reference, we can update its value in the DFSRec function and have that updated value reflected in the calling function (maxAreaOfIsland). This allows us to accumulate the area of the island as we explore its connected cells.

*/

//Code : 

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
        
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
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