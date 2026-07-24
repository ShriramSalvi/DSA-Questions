class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums1) {
    
     unordered_set<int>st;
     for(int i:nums1)st.insert(i);
     vector<int>nums;
     for(int i:st)nums.push_back(i);

     unordered_set<int>pairHash;

     for(int i=0; i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            pairHash.insert(nums[i]^nums[j]);
        }
     }

    unordered_map<int,int>mp;

    for(int i=0; i<nums.size();i++){
        for(int j:pairHash){
            mp[nums[i]^j]++;
        }
    }
     return mp.size();
    }
};