class Solution {
public:
    void helper( vector<vector<char>>&grid,int row,int col, int &m, int &n){

        if( row>=m || col>=n)return;
         if(grid[m-1][n-1]=='.')return;
        grid[row][col]='.';
        if(row==m-1 && col==n-1)return;
        helper(grid,row,col+1,m,n);
        helper(grid,row+1,col,m,n);
      
    }
    vector<string> createGrid(int m, int n) {
        
        vector<vector<char>>grid(m,vector<char>(n,'#'));

       

        helper(grid,0,0,m,n);

        for(int i=0; i<m; i++){
            
          for(int j=0; j<n;j++){
            cout<<grid[i][j]<<" ";
          }
          cout<<endl;
        }

        vector<string>ans;

        for(int i=0; i<m; i++){
            string temp="";
          for(int j=0; j<n;j++){
            temp.push_back(grid[i][j]);
          }
          ans.push_back(temp);
        }

        return ans;
    }
};