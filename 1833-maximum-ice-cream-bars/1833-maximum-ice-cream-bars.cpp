class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

      unordered_map<int,int>mp;

      for(int i:costs)mp[i]++;

      priority_queue<
      pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>>
      >minheap;

      for(auto it:mp)minheap.push({it.first,it.second});
      
      int count=0;
      while(!minheap.empty()){
        auto pair = minheap.top();
        int cost = pair.first;
        int totalIceCream = pair.second;
        minheap.pop();
        bool flag = true;
        while(totalIceCream){
            if(coins>=cost){
                coins-=cost;
                totalIceCream--;
                count++;
            }
            else{
                flag = false;
                break;
            }
        }
        if(!flag)break;
      }

      return count;
      
    }
};