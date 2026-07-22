class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int max= *max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());

        for(int i:nums)if(i!= max && i!=min)return i;

        return -1;
    }
};