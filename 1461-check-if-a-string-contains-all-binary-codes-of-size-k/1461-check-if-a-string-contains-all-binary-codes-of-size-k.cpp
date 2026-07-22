class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if(k>s.length())return false;

        int n=s.length();
        
        unordered_map<string,int>mp;

        for(int i=0; i<=n-k;i++)mp[s.substr(i,k)]++;

        return mp.size()==pow(2,k);
        
    }
};