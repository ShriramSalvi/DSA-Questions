class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN;

        int currentOneCount=0;

        int i=0;

        while(i<nums.size()){
            currentOneCount++;
            if(nums[i]==0){
                ans = max(ans,currentOneCount-1);
                currentOneCount=0;
           }
           i++;
        }
       ans= max(ans,currentOneCount);
        return ans;
    }
};