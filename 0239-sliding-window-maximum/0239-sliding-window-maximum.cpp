class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
         if(k==1)return nums;
        vector<int>ans;

        int left =0; 
        int right =0;


        deque<pair<int,int>>dq;

        while(right<k){
       
         while(dq.size() && dq.back().first<nums[right])dq.pop_back();
         dq.push_back({nums[right],right});
         right++;
        }


        while(right<nums.size()){

            while(dq.size() &&  dq.front().second < left )dq.pop_front();
            ans.push_back(dq.front().first);
            

            while(dq.size() && dq.back().first<nums[right])dq.pop_back();
            dq.push_back({nums[right],right});
            right++;
            left++;
        }

        while(dq.size() && dq.front().second<left)dq.pop_front();

        ans.push_back(dq.front().first);

        return ans;
    }
};