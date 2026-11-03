class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        int right=nums.size()-1;

        while(right>=0){
            if(mp.find(nums[right])!=mp.end())break;
            mp[nums[right]]=right;
            right--;
        }
       right+=1;

       if(right==0)return 0;

       if(right%3==0)return right/3;

       return (right/3)+1;
    }
};