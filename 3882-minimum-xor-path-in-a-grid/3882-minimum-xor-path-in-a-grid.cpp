class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>>dp(m,vector<bitset<1024>>(n));
        
        dp[0][0][grid[0][0]]=1;
        
         // filling first row
        int prevRowXor=grid[0][0];
        for(int i=1; i<n; i++){
            int currXor = grid[0][i]^prevRowXor;
            dp[0][i][currXor]=1;
            prevRowXor=currXor;
        }

        // filling first Colmn
         int prevColXor=grid[0][0];
        for(int i=1; i<m; i++){
            int currXor = grid[i][0]^prevColXor;
            dp[i][0][currXor]=1;
            prevColXor=currXor;
        }


        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(i==0 || j==0)continue;

                auto up = dp[i-1][j];
                auto right = dp[i][j-1];
                
                auto combined=up|right;

                for(int k=0; k<1024 ;k++){
                    if(combined[k]){
                        int xorValue = grid[i][j]^k;
                        dp[i][j][xorValue]=1;
                    }
                }
            }
        }

        auto temp = dp[m-1][n-1];

        for(int i=0; i<1024; i++){
            if(temp[i])return i;
        }

        return 0;
    }
};