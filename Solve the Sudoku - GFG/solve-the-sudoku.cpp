// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool safe(int i,int j,int k,int grid[N][N])
    {
        for(int r=0;r<N;r++)
        {
            if(grid[i][r]==k || grid[r][j]==k)
            return false;
        }
        int startrow=i-i%3;
        int startcol=j-j%3;
        for(int r=0;r<3;r++)
        {
            for(int c=0;c<3;c++)
            if(grid[r+startrow][c+startcol]==k)
            return false;
        }
        return true;
    }
    bool solve(int i,int j,int grid[N][N])
    {
        if(i==N-1 && j==N)
        return true;
        if(j==N)
        {
            i++;
            j=0;
        }
        if(grid[i][j]>0)
        return solve(i,j+1,grid);
        for(int k=1;k<=N;k++)
        {
            
                if(safe(i,j,k,grid))
                {
                    grid[i][j]=k;
                    if(solve(i,j+1,grid)==true)
                    return true;
                    grid[i][j]=0;
                }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        solve(0,0,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends