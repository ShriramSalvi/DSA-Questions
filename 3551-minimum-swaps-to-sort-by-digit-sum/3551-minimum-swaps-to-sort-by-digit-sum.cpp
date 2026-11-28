class Solution {
public:
    int digitSum(int n){
        int sum=0;

        while(n!=0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >minheap;

        

        for(int i=0; i<nums.size();i++)minheap.push({digitSum(nums[i]),nums[i]});
        
        // this map will store curr index after sorting
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size();i++)mp[nums[i]]=i;

        
        vector<int>sortedCopy;
        for(int i=0; i<nums.size();i++) {
        sortedCopy.push_back(minheap.top().second);
        minheap.pop();
         }
        
        int swapCount=0;

        for(int i=0; i<sortedCopy.size();i++){
          int expectedIndex = i; // it is from sortedCopy
          int currIndex = mp[sortedCopy[i]];

          if(expectedIndex != currIndex){
            swapCount++;
            swap(nums[currIndex],nums[expectedIndex]);
            
            // updating position after updation
            mp[nums[expectedIndex]] = expectedIndex;
            mp[nums[currIndex]] = currIndex;
          }
        }

        return swapCount;
    }
};