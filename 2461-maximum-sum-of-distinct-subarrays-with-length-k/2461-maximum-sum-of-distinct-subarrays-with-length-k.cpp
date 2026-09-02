class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long currSum =0;
        long long ans=0;

        int left =0;
        int right=0;

        unordered_map<int,int>mp;

        while(right<k){
            currSum += nums[right];
            mp[nums[right]]++;
            right++;
        }


        while(right<nums.size()){

            if(mp.size()==k)ans = max(currSum,ans);

            currSum -= nums[left];
            currSum += nums[right];

            mp[nums[left]]--;
            mp[nums[right]]++;

            if(mp[nums[left]]==0)mp.erase(nums[left]);
            left++;
            right++;
         }

        if(mp.size()==k)ans = max(currSum,ans);
         return ans;
    }
};