class Solution {
public:
    bool uniformArray(vector<int>& nums) {

        bool flagCheckAllOdd=true;

        for(int i:nums)
        if(i%2==0)flagCheckAllOdd=false;

        if(flagCheckAllOdd)return true;


        bool flagCheckAllEven = true;
        for(int i:nums)
        if(i%2==1)flagCheckAllEven=false;

        if(flagCheckAllEven)return true;


        
        int smallOdd = INT_MAX;
        int smallEven = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                smallEven = min(smallEven,nums[i]);
                continue;
            }
            smallOdd = min(smallOdd,nums[i]);
        }
      
      // if we want to convert even number into odd via keeping result positive small even - small odd > = 1 as specified 

      return  (smallEven - smallOdd)>=1  ; // indicates convertable to odd



    }
};