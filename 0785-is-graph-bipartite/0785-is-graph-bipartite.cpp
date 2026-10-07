class Solution {
public:
    void dfs(
     unordered_map<int,vector<int>>&mp,
     vector<int>&visited,
     int currVertex,
     int currVertexColor,
     bool &flag
    ){
        if(visited[currVertex]!=-1)return;
        visited[currVertex]=currVertexColor;

        for(int i:mp[currVertex]){

          if(visited[i]!=-1 && visited[i]==currVertexColor){
            flag=false;
            return;
          }
          else if(visited[i]!=-1)continue;
          else{
            dfs(mp,visited,i,1-currVertexColor,flag);
          }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>visited(graph.size(),-1);

        unordered_map<int,vector<int>>mp;

        for(int i=0; i<graph.size();i++){
            mp[i]=graph[i];
        }
        
        bool flag=true;
        
        for(int i=0; i<graph.size();i++){
            if(!flag)return false;
            dfs(mp,visited,i,1,flag);
        }

        return flag;
    }
};