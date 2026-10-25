class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid,int row, int col){
        if(row<0 || row>=grid.size() || col<0  || col>=grid[0].size())return false;
        if(grid[row][col]==1)return true;
        
        grid[row][col]=1;

        bool right = dfs(grid, row, col + 1);
        bool left  = dfs(grid, row, col - 1);
        bool down  = dfs(grid, row + 1, col);
        bool up    = dfs(grid, row - 1, col);
        
        return right && left && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int count=0;
    for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[i].size();j++){
            if(grid[i][j]==0 && dfs(grid,i,j))count++;
        
        }
       } 

       return count;
    }
};