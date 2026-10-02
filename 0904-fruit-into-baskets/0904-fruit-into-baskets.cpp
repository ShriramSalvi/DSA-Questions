class Solution {
public:
    int totalFruit(vector<int>& nums) {
       int ans = 0;

       int left=0;
       int right=0;

       unordered_map<int,int>mp;

       while(right<nums.size()){
        mp[nums[right]]++;
        
        while( mp.size()>2){
            mp[nums[left]]--;
            if(mp[nums[left]]==0)mp.erase(nums[left]);
            left++;
        }
         ans = max(ans,right-left+1);
        right++;
       }

    //    while( mp.size()>2){
    //         mp[nums[left]]--;
    //         if(mp[nums[left]]==0)mp.erase(nums[left]);
    //         left++;
    //     }
    //     ans = max(ans,right-left+1);
       return ans;
    }
};