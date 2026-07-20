class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        k= k%(grid.size()*grid[0].size());

        vector<int>temp;

        for(int i=0; i<grid.size();i++)
            for(int j:grid[i])temp.push_back(j);

        


       reverse(temp.begin(), temp.end());
       reverse(temp.begin(), temp.begin() + k);
       reverse(temp.begin() + k, temp.end());

        int idx=0;
        
      for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[0].size();j++){
            grid[i][j]=temp[idx];
            idx++;
        }
      }

      return grid;
    }
};