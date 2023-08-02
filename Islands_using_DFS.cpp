#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>&grid, int i, int j){
    int row = grid.size();
    int col = grid[0].size();
    
    if (i < 0 || j < 0 || i > (row - 1) || j > (col - 1)
        || grid[i][j] != 1) {
        return;
    }
 
    if(grid[i][j] == 1){
        grid[i][j] = 0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j+1);
        dfs(grid,i-1,j-1);
        dfs(grid,i-1,j+1);
        dfs(grid,i+1,j-1);
    }
}

int countIslands(vector<vector<int>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    int cnt = 0;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == 1){
                cnt++;
                dfs(grid,i,j);
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> grid = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1 } 
    };
    cout<< "No.of Islands = " << countIslands(grid) <<endl;
    return 0;
}