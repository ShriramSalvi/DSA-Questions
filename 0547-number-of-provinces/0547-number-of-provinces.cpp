class Solution {
public:
    void dfs( 
        unordered_map<int,vector<int>>&mp,
        vector<bool>&visited,
        int currVertex
   ){
   
    visited[currVertex]=true;

    for(int i:mp[currVertex]){
        if(!visited[i]){
            dfs(mp,visited,i);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
      unordered_map<int,vector<int>>mp;

      for(int i=0; i<isConnected.size();i++){
        for(int j=0;j<isConnected.size();j++){
            if(i!=j && isConnected[i][j]){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
      }
     
     vector<bool>visited(isConnected.size(),false);
     int provincesCount=0;
     for(int i=0;i<isConnected.size();i++){
        if(!visited[i]){
            dfs(mp,visited,i);
            provincesCount++;
        }
     }
    return provincesCount;
    }
};