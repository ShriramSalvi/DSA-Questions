class Solution {
public:
    int helper(int left, int right, string &s,vector<vector<int>>&dp){
    while(left<=right){
        if(s[left]!=s[right]){
            return 0;
        }
        left++,right--;
    }
    return 1;
}
    int countSubstrings(string s) {
 
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        int count=0;

        for(int i=0; i<s.length();i++){
        for(int j=i;j<s.length();j++){
          if(dp[i][j]!= -1){
            count+=dp[i][j];
          }
          else{
            dp[i][j]=helper(i,j,s,dp);
            count+=dp[i][j];
          }
        }
        }

        
        return count;

    }
};