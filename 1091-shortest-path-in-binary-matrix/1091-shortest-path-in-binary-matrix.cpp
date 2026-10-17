class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0]||grid[n-1][n-1])return -1;

        deque<pair<int,int>>dq;
        int ans=0;

        dq.push_back({0,0});
        grid[0][0]=1;
        bool flag = false;

        while(!dq.empty()){
            int size = dq.size();
           
            
      for(int k=0; k<size;k++){
           auto pair = dq.front();
            dq.pop_front();
            int row = pair.first;
            int col=pair.second;
           
            if(row==n-1 && col==n-1){
                flag = true;
                break;
            }
      
           

            if(row<n && col+1<n && !grid[row][col+1]){
                dq.push_back({row,col+1});
                grid[row][col+1]=1;
            }//going right
            if(row+1<n && col<n && !grid[row+1][col]){
                dq.push_back({row+1,col});
                grid[row+1][col]=1;
            }
            // going down
            if(row-1>=0 && col>=0 && !grid[row-1][col]){
                dq.push_back({row-1,col});
                grid[row-1][col]=1;
                }//going left;
            if(row>=0 && col-1>=0 && !grid[row][col-1]){
                dq.push_back({row,col-1});
                grid[row][col-1]=1;
                }//going up;

            // cross movements across diagonals 

            if(row+1<n && col+1<n && !grid[row+1][col+1]){
                dq.push_back({row+1,col+1});
                grid[row+1][col+1]=1;
             }//bootom right
            if(row+1<n && col-1 >=0 && !grid[row+1][col-1]){
                dq.push_back({row+1,col-1});
                grid[row+1][col-1]=1;
            }//bottom left
            if(row-1>=0 && col+1<n && !grid[row-1][col+1]){
                dq.push_back({row-1,col+1});
                grid[row-1][col+1]=1;
            }//up right
            if(row-1>=0 && col-1>=0 && !grid[row-1][col-1]){
                dq.push_back({row-1,col-1});
                grid[row-1][col-1]=1;
            }
        }
        
            ans++;
           
           if(flag)break;
        }
        if(!grid[n-1][n-1])return -1;
        return ans;
    }
};