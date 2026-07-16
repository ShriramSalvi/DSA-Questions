class Solution {
public:
    long long gcdSum(vector<int>& nums) {

      vector<int>maxElements;
      int largest = INT_MIN;

      for(int i:nums){
        largest = max(largest,i);
        maxElements.push_back(largest);
      } 

      vector<int>GCD;

      for(int i=0; i<nums.size();i++)GCD.push_back(__gcd(nums[i],maxElements[i]));

      sort(GCD.begin(),GCD.end());

      long long ans=0;

      int left=0; 
      int right=GCD.size()-1;

      while(left<right) ans+= __gcd(GCD[left++],GCD[right--]);

      return ans;
      
    }
};