class Solution {
public:
    int minimumPushes(string word) {
        
       unordered_map<char,int>mp;

       for(char ch:word)mp[ch]++;

       priority_queue<pair<int,char>>heap;

       for(auto it:mp)heap.push({it.second,it.first});

       if(heap.size()<=8)return word.length();

       int count=0;

       int ans=0;

       while(heap.size()) {
        auto it = heap.top();
        heap.pop();
        count++;
        if(count<=8){
            ans+= it.first;
        }
        else if(count>8 && count<=16){
            ans+= (it.first*2);
        }
        else if(count>16 && count<=24){
            ans+= (it.first)*3;
        }
        else{
            ans+= (it.first)*4;
        }
       }
       return ans;
    }
};