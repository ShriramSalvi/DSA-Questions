class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        
        long long ans=0;
        int evenCount=1;
        int oddCount=0;
        vector<int>prefixSum;
        prefixSum.push_back(0);

        for(int i=0; i<nums.size();i++){
              prefixSum.push_back(prefixSum[prefixSum.size()-1]+nums[i]);
               
               if((prefixSum[prefixSum.size()-1])%2){
                ans+=evenCount;
                oddCount++;
               }
               else {
                evenCount++;
                ans+=oddCount;
               }
            
        }

        
        long long modulo = 1e9+7;
        int finalAns = ans%modulo;

        return finalAns;
    }
};