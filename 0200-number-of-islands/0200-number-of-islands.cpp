class Solution {
public:
    int dfs(vector<vector<char>>& grid ,int row, int col){
        if(row<0 || row>=grid.size() || col<0  || col>=grid[0].size())return 0;
        if(grid[row][col]=='0')return 0;
        grid[row][col]='0';
        dfs(grid,row,col+1);// going right
        dfs(grid,row,col-1);// going left
        dfs(grid,row+1,col);// going down
        dfs(grid,row-1,col);// going up

        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {

       int count=0;

       for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[i].size();j++){
            if(dfs(grid,i,j))count++;
        }
       } 

       return count;
    }
};