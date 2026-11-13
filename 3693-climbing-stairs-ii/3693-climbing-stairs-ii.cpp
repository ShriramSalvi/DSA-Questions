class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1);

        
        dp[0]=0;
        
        for(int i=1; i<dp.size();i++){
            int cost = costs[i-1];
            if(i==1){
                dp[i]=cost+1;
                continue;
            }
            if(i==2){
                dp[i]=cost+min(dp[1]+1,4);//4 indicates (2-0)^2;
                continue;
            }
            int step1Back = dp[i-1]+1;
            int step2Back=dp[i-2]+4;
            int step3Back=dp[i-3]+9;

            dp[i]=cost+min({step1Back,step2Back,step3Back});
        }

        return dp[dp.size()-1];
    }
};