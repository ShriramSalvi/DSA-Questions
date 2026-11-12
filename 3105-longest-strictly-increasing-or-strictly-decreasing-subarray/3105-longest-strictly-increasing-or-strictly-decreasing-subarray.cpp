class Solution {
public:
    int increasingSubarrayLength(vector<int>& nums){
        int ans =1 ;
        int left=0;
        int right=1;

        while(right<nums.size()){
            if(nums[right]<=nums[right-1]){
                ans = max(ans,right-left);
                left=right;
            }
            right++;
        }

        ans = max(ans,right-left);
        return ans;
    }
    int decreasingSubarrayLength(vector<int>& nums){
        int ans=1;
        int left=0;
        int right=1;

        while(right<nums.size()){
            if(nums[right]>=nums[right-1]){
                ans=max(ans,right-left);
                left=right;
            }
            right++;
        }
        ans = max(ans,right-left);
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
      return max(increasingSubarrayLength(nums),decreasingSubarrayLength(nums));
    }
};