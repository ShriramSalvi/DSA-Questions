class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = INT_MIN;
        
        int left=0; 
        int right=0;

        while(right<nums.size()){
            if(nums[right]==0)k--;
            
            
          while(k<0){
                if(nums[left]==0)k++;
                left++;
            }

            ans = max(ans,right-left+1);
            
            right++;
        }
           
        

        
       
        return ans;
    }
};