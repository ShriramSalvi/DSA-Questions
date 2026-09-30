class Solution {
public:
    int countSubstrings(string s) {
        
        vector<vector<int>>dp(1001,vector<int>(1001,0));
        
        int count =0;

       for(int length=1; length<=s.length();length++){
        for(int i=0; length+i-1<s.length();i++){
            int j= length+i-1;
            
            if(i==j){
                dp[i][j]=1;
                
            }
            else if(i+1==j && s[i]==s[j]){
                dp[i][j]=1;
               
            }
            else if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
            }
            if(dp[i][j])count++;
        }
       }

        return count;
    }
};