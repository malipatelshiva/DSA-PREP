//Link : https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

//code :
class Solution {
  public:
  
    bool isValid(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        if( i>=0 && i<m && j>=0 && j<n && grid[i][j]=='L')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void DFSRec(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        grid[i][j] = 'W';
        if(isValid(grid,i+1,j,m,n))
            DFSRec(grid,i+1,j,m,n);
            
        if(isValid(grid,i-1,j,m,n))
            DFSRec(grid,i-1,j,m,n);
            
        if(isValid(grid,i,j+1,m,n))
            DFSRec(grid,i,j+1,m,n);
            
        if(isValid(grid,i,j-1,m,n))
            DFSRec(grid,i,j-1,m,n);
        
        //Diagonal direction    
        if(isValid(grid,i+1,j+1,m,n))
            DFSRec(grid,i+1,j+1,m,n);
            
        if(isValid(grid,i+1,j-1,m,n))
            DFSRec(grid,i+1,j-1,m,n);
            
        if(isValid(grid,i-1,j+1,m,n))
            DFSRec(grid,i-1,j+1,m,n);
            
        if(isValid(grid,i-1,j-1,m,n))
            DFSRec(grid,i-1,j-1,m,n);

    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='L')
                {
                    count++;
                    DFSRec(grid,i,j,m,n);
                }
            }
        }
        return count;

        
    }
};