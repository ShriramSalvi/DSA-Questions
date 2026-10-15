class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

      unordered_map<int,vector<int>>mp;

      for(auto it:edges){
        mp[it[0]].push_back(it[1]);
        mp[it[1]].push_back(it[0]);
      }

      vector<bool>visited(n,false);

      visited[source]=true;

      deque<int>dq;

      dq.push_back(source);

      while(!dq.empty()){
        int currNode = dq.front();
        dq.pop_front();
        for(int i:mp[currNode]){
         if(!visited[i]){
            visited[i]=true;
            dq.push_back(i);
         }
        }
      }

      return visited[destination];
    }
};