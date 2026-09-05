//Link 

/*  Notes:
    1.Instead of just counting the cells in an island, 
    2.we need to remember the relative positions of all cells in that island and use that as the island's "shape".
        The key concept is relative coordinates.

*/

class Solution {
	public:
	
	bool isValid(vector<vector<char>> & grid, int i, int j, int m, int n)
	{
		if (i >= 0 && i<m && j >= 0 && j<n && grid[i][j] == 'L')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void DFSRec(vector<vector<char>> & grid, int i, int j, int sr,int sc,int m, int n,vector<pair<int,int>>&Shapes)
	{
		grid[i][j] = 'W';
		
		Shapes.push_back({i-sr,j-sc});
		
		if (isValid(grid, i + 1, j, m, n))
			DFSRec(grid, i + 1, j,sr,sc,m,n,Shapes);
		
		if (isValid(grid, i - 1, j, m, n))
			DFSRec(grid, i - 1, j,sr,sc,m, n,Shapes);
		
		if (isValid(grid, i, j + 1, m, n))
			DFSRec(grid, i, j + 1,sr,sc,m, n,Shapes);
		
		if (isValid(grid, i, j - 1, m, n))
			DFSRec(grid, i, j - 1,sr,sc,m, n,Shapes);
		
	}
	
	int countDistinctIslands(vector<vector<char>> & grid) {
		// code here
		
		int m = grid.size();
		int n = grid[0].size();
		
		set<vector<pair<int,int>>>uniqueShapes;
		
		int count = 0;
		for (int i = 0; i<m; i++)
		{   
		    
    		for (int j = 0; j<n; j++)
    		{
        		if (grid[i][j] == 'L')
        		{
        		    vector<pair<int,int>>Shapes;
        		    int sr = i;
        		    int sc = j;
        			DFSRec(grid, i, j,sr,sc, m, n,Shapes);
        			uniqueShapes.insert(Shapes);
        		 }
    		}
		}
		
		return uniqueShapes.size();
		
	}
};


/*   important points
    1. vector<pair<int,int>>Shapes; should be declared inside the if condition, so that for each new island, we start with a fresh vector to store its shape.
    2. if i put that outside j loop, then Shapes is created once per row, and it will accumulate the shapes of all islands in that row, 
    3.which is not what we want. We want to capture the shape of each individual island separately.
    

    4. Data Structure
    set<vector<pair<int,int>>> uniqueShapes;
    vector<pair<int,int>> → represents one island's shape.
    set → stores only unique shapes.

    unordered_set<vector<pair<int,int>>> cannot be used directly because C++ does not provide a default hash for vector<pair<int,int>>. A custom hash would be required.

    5. The relative coordinates are calculated as (i - sr, j - sc), where (sr, sc) is the starting point of the island. This ensures that islands with the same shape but located in different parts of the grid are considered identical.
    here, relative positons are important to identify the shape of island. Because if we do not use relative positions then two islands with same shape but different positions will be considered different islands.
     Hence we use relative positions to identify the shape of island.




     Time comlexity :


     Let:

m = number of rows
n = number of columns
N = m × n = total cells
1. Traversing the grid

You have:

for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        ...
    }
}

This visits every cell once:

m × n = N

So:

O(m × n)

2. DFS

When you find an island:

DFSRec(...)

Inside DFS, you mark every land cell as visited:

grid[i][j] = 'W';
Shapes.push_back({i-sr, j-sc});

A cell becomes 'W', so it will never be visited again by DFS.

Therefore, across the entire algorithm, DFS processes each cell at most once.

So DFS is also:

O(m × n)

3. Then where does log(m × n) come from?

This line:

uniqueShapes.insert(Shapes);

You are using:

set<vector<pair<int,int>>> uniqueShapes;

A set is typically implemented as a balanced binary search tree.

Suppose there are K different island shapes.

For every insertion, the set may need to search through the tree.

The height of the tree is approximately:

log K

And because:

K <= number of cells <= m × n

we simplify it to:

log(m × n)

So the simplified analysis says:

DFS/grid traversal       → O(m × n)
set insertion            → O(m × n log(m × n))
------------------------------------------------
Total                    → O(m × n log(m × n))

Since the second term dominates:

Time = O(m × n log(m × n))

But there is an important detail

Your set contains:

vector<pair<int,int>>

When comparing two shapes, C++ may compare their vectors element-by-element.

So the strictly precise complexity gets more complicated because an island can contain many cells.

For interview/DSA purposes, though, the commonly accepted simplified answer for your implementation is:

Time:  O(m × n log(m × n))
Space: O(m × n)
Easy way to remember

Think of your code as doing two major things:

1. Explore the entire grid
       ↓
   O(m × n)

2. Store unique shapes in SET
       ↓
   SET → log(...)

Therefore:

O(m × n) × log(m × n)
        ↓
O(m × n log(m × n))

The key point: DFS is not giving you the log. The log comes from using set.


*/