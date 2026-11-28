class Solution {
public:
    int m;
    int n;
    bool helper(int row, int col,vector<vector<int>>&grid,int power , vector<vector<int>>&dp){

        if(row<0 || col<0 || row>=m || col>= n)return false;
        if(grid[row][col]==-1)return false;

        power -= grid[row][col];
        if(power<=0)return false;
        if(dp[row][col]>=power)return false;

        if(row==m-1 && col==n-1)return true ;
      

         dp[row][col]=power;
        // will need backtracking
         int temp = grid[row][col];
         grid[row][col]=-1;
        
         bool up = helper(row-1,col,grid,power,dp);
         bool down = helper(row+1,col,grid,power,dp);
         bool right = helper(row,col+1,grid,power,dp);
         bool left=helper(row,col-1,grid,power,dp);

         grid[row][col]=temp;

        return (up || down || right || left);


    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n= grid[0].size();
        
        cout<<m<<" "<<n;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,grid,health,dp);

        // return true;
    }
};