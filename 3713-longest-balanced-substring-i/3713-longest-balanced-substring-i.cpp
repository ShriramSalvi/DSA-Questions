class Solution {
public:
    int longestBalanced(string s) {

      int ans =0;

      for(int i=0;i<s.length();i++){
        unordered_map<char,int>mp;
        for(int j=i;j<s.length();j++){
            mp[s[j]]++;
            int targetFrequency = mp[s[i]];
            bool flag = true;
            for(auto it:mp){
              if(it.second!=targetFrequency){
                flag=false;
                break;
              }
            }
            if(flag)ans=max(ans,(j-i+1));
        }
     }

      return ans;  
    }
};