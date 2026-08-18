class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int>temp(26,0);

        for(char ch:s)temp[ch-'a']++;

        unordered_map<int,string>mp;

        for(int i=0; i<temp.size();i++){
            if(!temp[i])continue;
            mp[temp[i]].push_back((i+'a'));
        }
        
        string ans="";
        int currFrequency=0;

        for(auto it:mp){
            if(ans.size()<it.second.size()){
                ans = it.second;
                currFrequency = it.first;
            }
           else if(ans.size()==it.second.size() && it.first>currFrequency){
             currFrequency = it.first;
             ans = it.second;
            }
        }

        return ans;
    }
};