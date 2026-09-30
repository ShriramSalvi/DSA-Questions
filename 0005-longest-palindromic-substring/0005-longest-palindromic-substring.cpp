class Solution {
public:
    string longestPalindrome(string s) {

        string ans = "";

        vector<vector<bool>> dp(1001, vector<bool>(1001, false));

        for (int length = 1; length <= s.length(); length++) {
            for (int i = 0; i + length - 1 < s.length(); i++) {
                int j = i + length - 1;
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j && s[i] == s[j]) {
                    dp[i][j] = true;
                } else if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                }

                if (dp[i][j] == true && ans.length() < length) {
                    string temp = "";
                    for (int k = i; k <= j; k++)
                        temp.push_back(s[k]);
                    ans = temp;
                }
            }
        }

        return ans;
    }
};