class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

      unordered_map<int,vector<int>>rows;
      unordered_map<int,vector<int>>cols;

      for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[0].size();j++){
            if(grid[i][j]){
               rows[i].push_back(1);
               cols[j].push_back(1);
            }
        }
      }

      int ans=0;

    for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[0].size();j++){
         if(grid[i][j] && (rows[i].size()>1 || cols[j].size()>1))ans++;
        }
      }

      return ans;
    }
};