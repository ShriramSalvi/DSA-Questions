class Solution {
public:
    int maximumProduct(vector<int>& nums) {
     
     int n = nums.size();
     if(n<4)return nums[n-1]*nums[n-2]*nums[n-3];

     sort(nums.begin(),nums.end());

     int firstTwoProduct = nums[0]*nums[1];
     int lastTwoProduct = nums[n-1]*nums[n-2];

     int thirdElement1 = INT_MIN;
    int thirdElement2=INT_MIN;
 
     for(int i=2; i<nums.size();i++)thirdElement1 = max(thirdElement1,nums[i]);
     
      for(int i=n-3;i>=0;i--)thirdElement2 = max(thirdElement2,nums[i]);
    
    
    return max(thirdElement1*firstTwoProduct,thirdElement2*lastTwoProduct);
      
    }
};