class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int left=0;
        int right=nums.size()-1;

        vector<int>temp = nums;

        sort(temp.begin(),temp.end());

        if(temp==nums)return 0;

        while(left<nums.size()&&temp[left]==nums[left])left++;
   

        while(right>=0 && temp[right]==nums[right])right--;

    
       
        return right-left+1;
    }
};