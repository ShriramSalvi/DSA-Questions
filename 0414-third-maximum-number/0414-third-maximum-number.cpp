class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>temp;
        priority_queue<int,vector<int>,greater<int>>minheap;

        for(int i:nums)temp.insert(i);

        for(auto i:temp){
            minheap.push(i);
            if(minheap.size()>3)minheap.pop();
        }
     
     if(minheap.size()==3)return minheap.top();

     while(minheap.size()!=1)minheap.pop();

     return minheap.top();
        
    }
};