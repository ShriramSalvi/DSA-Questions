class Solution {
public:
    int minPartitions(string s) {
        int ans = INT_MIN;

        for(char n:s)ans = max(ans,n-'0');
            
        
        return ans;
    }
};