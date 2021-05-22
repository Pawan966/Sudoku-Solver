#include<bits/stdc++.h>
using namespace std;

/**** Function to check whether a number can be filled at grid[row][col] 
      returns true if possible to insert num at grid[row][col]
      otherwise returns false 
*****/
bool possible(int grid[9][9], int row, int col, int num)
{
	for(int i=0;i<9;i++)
	{
		if(grid[row][i]==num)
			return false;
	}

	for(int i=0;i<9;i++)
	{
		if(grid[i][col]==num)
			return false;
	}

	int r=(row/3)*3;
	int c=(col/3)*3;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i+r][j+c]==num)
				return false;
		}
	}

	return true;
}

/*** Function that prints the solution to the given grid ***/
void printGrid(int grid[9][9], int &check)
{   
	check=1;

	for(int row=0;row<9;row++)
	{
		for(int col=0;col<9;col++)
			cout<<grid[row][col]<<" ";

		cout<<"\n";
	}

	cout<<"\n";
}

/*** Function that solves the given grid using backtracking and recursion***/
void solve(int grid[9][9], int &check)
{
	for(int row=0; row<9; row++)
	{
		for(int col=0; col<9; col++)
		{
			if(grid[row][col]==0)
			{
				for(int num=1; num<=9; num++)
				{
					if(possible(grid,row,col,num))
					{
						grid[row][col]=num;
						solve(grid,check);
						grid[row][col]=0;
					}
				}
                check=0;
				return;
			}
		}
	}
    
    printGrid(grid,check);

	cout<<"Want more solutions.... press m\n";
	cout<<"Otherwise to exit the program... press e\n";

    char ch;
    cin>>ch;

    if(ch=='e')
    exit(0);

    else
    cout<<"The Solution is:\n";	

}

int main()
{
	int grid[9][9];  // sudoku initial grid

	cout<<"Enter numbers in the grid row by row\n";
	cout<<"1. If the cell is empty, enter 0\n";
	cout<<"2. Otherwise enter the number from 1 to 9\n";

    for(int row=0; row<9; row++)
    {
    	for(int col=0; col<9; col++)
    		cin>>grid[row][col];
    }
    
    int check=0;
    cout<<"\nThe Solution is:\n";

    bool found=false;
    for(int row=0;row<9;row++)
    {
    	for(int col=0;col<9;col++)
    	{
    		if(grid[row][col]==0)
    	    {
    	    	found=true;
    	    	break;
    	    }
    	}
    }

    if(!found)
    {
    	printGrid(grid,check);
    	cout<<"No More Solutions Exist\n";
    	return 0;
    }

    solve(grid,check);

    if(check==0)
      cout<<"No More Solutions Exist\n";	
    
    return 0;
}