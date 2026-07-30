class Solution {
public:
    bool check(vector<int>& nums) {
        
        nums.push_back(nums[0]);
        
        int count =0;

        for(int i=0; i<nums.size()-1;i++){
            if(nums[i+1]<nums[i])count++;
        }
        return count<=1;
    }
};