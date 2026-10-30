class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[m-1][n-1]==1 || grid[0][0]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n));

        // filling first row
        int cellMark=1;
        for(int i=0;i<n;i++){
            if(grid[0][i])cellMark=0;
            dp[0][i]=cellMark;
        }

        // filling first column
         cellMark=1;
        for(int i=0; i<m;i++){
            if(grid[i][0])cellMark=0;
            dp[i][0]=cellMark;
        }
        
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || grid[i][j]==1)continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};