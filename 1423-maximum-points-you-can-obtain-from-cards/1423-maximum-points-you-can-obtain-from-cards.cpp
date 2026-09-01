class Solution {
public:
    int maxScore(vector<int>& nums, int k) {

       int sum =0;
       
       int left=0;
       while(left<k){
        sum+=nums[left];
        left++;
       }
       left--;
       

       int right=nums.size()-1;
       
       int currSum = sum;
      while(left>=0){
        currSum -= nums[left];
        currSum += nums[right];
        sum = max(sum,currSum);
        left--;
        right--;
      }

       return sum;
    }
};