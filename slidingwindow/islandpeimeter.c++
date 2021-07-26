#include<bits/stdc++.h>
using namespace std;


    int islandPerimeter(vector<vector<int>>& grid)


    {
        int peri = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int inpei = 4;
                    if(j!=0&&grid[i][j-1]==1)
                        inpei--;
                    if(j!=grid[i].size()-1&&grid[i][j+1]==1)
                        inpei--;
                    if(i!=0&&grid[i-1][j]==1)
                        inpei--;
                    if(i!=grid.size()-1&&grid[i+1][j]==1)
                        inpei--;


                    peri+=inpei;
                }
            }
        }
        return peri;
    }
int main()
{
    vector<vector<int>>grid={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<islandPerimeter(grid);
}
