class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));

        // filling first row

        for(int i=0; i<n; i++)dp[0][i]=matrix[0][i];

        for(int row=1; row<n;row++){
            for(int col=0; col<n;col++){
                int leftDiagonal = INT_MAX;
                int rightDiagonal=INT_MAX;

                int upperCell=dp[row-1][col];

                if(col-1>=0)leftDiagonal = dp[row-1][col-1];

                if(col+1<n)rightDiagonal=dp[row-1][col+1];

                dp[row][col]=matrix[row][col]+ min(leftDiagonal ,min(rightDiagonal,upperCell));
                
            }

        }


     int ans = INT_MAX;

     for(int i=0;i<n;i++)ans=min(ans,dp[n-1][i]);

     return ans;
         
    }
};