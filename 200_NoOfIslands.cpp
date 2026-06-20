
// 200. Number of Islands
// link -> https://leetcode.com/problems/number-of-islands/description/

// t.c ->O(m * n)
// s.c ->O(m * n)

//Approach -> (easy brute)
// 1.Traverse each cell of the grid.
// 2.Whenever a cell contains '1' (land), it means we have discovered a new island.
// 3.Increment the island count.
// 4.Start a DFS from that cell and visit all connected land cells (up, down, left, 5.right).
// 6.Mark every visited land cell as '0' (water) so it is not counted again.
// 7.Continue scanning the grid until all cells are processed.
// 8.The number of times DFS is started equals the number of islands.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

void dfs(vector<vector<int>>&grid , int row ,int col){
    int m = grid.size();
    int n = grid[0].size();


    //out of bound condition
    if (row<0 ||row>=m || col < 0 || col >= n || grid[row][col] == '0') return ;
    
    grid[row][col] = '0';  //mark as visited

    //exploring all possible 4 directions
    dfs(grid,row+1,col);
    dfs(grid,row-1,col);
    dfs(grid,row,col+1);
    dfs(grid,row,col-1);
}


int numIsIslands(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    int islands=0;

    for(int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            if (grid[i][j]==1){
                islands++;
                dfs(grid,i,j);
            }
        }
    }
    return islands;
}
};

int main(){
    int m , n;
    cin>>m>>n;

    vector<vector<int>>grid;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j) 
            cin>>grid[i][j];

    Solution obj ;
    cout<<obj.numIsIslands(grid);
    
    return 0;
}
