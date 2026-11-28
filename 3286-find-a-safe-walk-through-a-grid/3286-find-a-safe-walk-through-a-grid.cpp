class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        /// submission 1 is done with dp + backtracking

        /// solution 2 can be done with dijekstra

        /// solution 3 is of 0/1 bfs
        
        int m = grid.size();
        int n= grid[0].size();

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        result[0][0]=grid[0][0];// source ---> source

        deque<pair<int,int>>dq; // row , col
        
        dq.push_back({0,0});
        
        vector<vector<int>>directions = {
            {-1,0},
            {1,0},
            {0,1},
            {0,-1}
        };

        while(!dq.empty()){

            auto[r,c] = dq.front();
            dq.pop_front();

            for(auto it:directions){

                int nR = it[0]+r;
                int nC = it[1]+c;

                if(nR<0 || nR >= m || nC<0 || nC >= n)continue;

                if(result[nR][nC] > result[r][c]+grid[nR][nC]){
                  result[nR][nC] =  result[r][c]+grid[nR][nC];

                  // wt = 0 insert front 
                  // wt = 1 insert back

                  if(grid[nR][nC]==0)dq.push_front({nR,nC});
                  else dq.push_back({nR,nC});
                }
            }
        }

            return (health - result[m-1][n-1]) >= 1;
        
    }
};