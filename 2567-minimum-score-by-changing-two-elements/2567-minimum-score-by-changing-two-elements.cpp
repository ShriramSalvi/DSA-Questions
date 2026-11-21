class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3)return 0;

        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        // case 1 reducing by both
        int score1 = nums[n-2]-nums[1];
        
        // reducing from start
        int score2=nums[n-1]-nums[2];

        // reducing from end
        int score3 =  nums[n-3]-nums[0];

        return min({score1,score2,score3});
    }
};