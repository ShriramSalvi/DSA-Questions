class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        

        unordered_map<int, vector<int>>mp;

        for(int i=0; i<nums.size();i++) mp[nums[i]].push_back(i);
         
         int ans = INT_MAX;

        for(auto it:mp){
           if(it.second.size()>=3){
             
            int i=0;
            int diff= INT_MAX;
            while(i+2 < it.second.size()){
              diff =
               min(diff,
                abs(it.second[i]-it.second[i+1])+
                abs(it.second[i]-it.second[i+2])+
                abs(it.second[i+1]-it.second[i+2])
                );
                i++;   
            }

             ans = min(ans,diff);
           }
        }
        if(ans == INT_MAX)return -1;
        return ans;
        
    }
};