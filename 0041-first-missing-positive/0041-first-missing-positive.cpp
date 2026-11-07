class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        bool flag_1 = false;

        for(int i:nums){
            if(i==1){
                flag_1=true;
                break;
            }
        }

        if(!flag_1)return 1;
 
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>n)nums[i]=1;
        }

        for(int i=0; i<n;i++){
            int idx = abs(nums[i]);
           if(nums[idx-1]>0) nums[idx-1]= (-nums[idx-1]);
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0)return i+1;
        }
        
     
        return n+1;
    }
};