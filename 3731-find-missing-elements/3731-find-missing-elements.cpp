class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

       int smallest = *min_element(nums.begin(),nums.end());
       int largest = *max_element(nums.begin(),nums.end());

       unordered_map<int,int>mp;
       vector<int>ans;
       for(int i:nums)mp[i]++;

       for(int i=smallest+1;i<largest;i++){
        if(mp.find(i)==mp.end())ans.push_back(i);
       }

       return ans;
    }
};