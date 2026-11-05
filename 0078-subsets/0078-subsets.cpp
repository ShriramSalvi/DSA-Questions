class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

       vector<vector<int>>ans;
       int maskSize=pow(2,nums.size());

       for(int mask=0; mask<maskSize; mask++){
           vector<int>temp;
           
           for(int i=0; i<nums.size();i++){
            if(mask & (1<<i))temp.push_back(nums[i]);
           }
           ans.push_back(temp);
       }

       return ans;
    }
};