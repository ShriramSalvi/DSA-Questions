class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        
        unordered_map<int,vector<vector<int>>>mp;

        for(int i=0; i<points.size();i++){
         for(int j=i+1; j<points.size();j++){
           
           int x1=points[i][0];
           int y1=points[i][1];
           int x2=points[j][0];
           int y2=points[j][1];

           int dist = abs(x1-x2)+abs(y1-y2);

           mp[i].push_back({j,dist});
           mp[j].push_back({i,dist});
         }
        }


        
        vector<bool>visited(points.size(),false);


        int ans=0;

        //{wt,vertex}

        priority_queue<
         pair<int,int>,
         vector< pair<int,int>>,
         greater< pair<int,int>>
      >minheap;

        

        // visited[{points[0][0],points[0][1]}]=true;
        
        minheap.push({0,0});

        while(!minheap.empty()){

            auto temp = minheap.top();
            minheap.pop();

            int wt=temp.first;
           int currVertex=temp.second;
            
            if(visited[currVertex])continue;

            ans+=wt;
            visited[currVertex]=true;

            for(auto it:mp[currVertex]){

                 
                if(!visited[it[0]]){
                    minheap.push({it[1],it[0]});
                }
            }
        }
        return ans;

        
    }
};