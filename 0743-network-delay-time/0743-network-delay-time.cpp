class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


    unordered_map<int,vector<vector<int>>>mp;

    for(auto it:times){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        mp[u].push_back({v,w});
    }

    vector<int>visited(n+1,INT_MAX);
    
    visited[k]=0;

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >minheap;

    minheap.push({0,k});

    while(!minheap.empty()){
        int w=minheap.top().first;
        int u = minheap.top().second;
        
        minheap.pop();

        for(auto it:mp[u]){

            int v=it[0];
            int currWeight=it[1];

          if(w+currWeight<visited[v]){
                visited[v]=w+currWeight;
                minheap.push({visited[v],v});
            }
        }
    }
     
        int ans=0;

        for(int i=1; i<visited.size();i++){
            if(visited[i]==INT_MAX)return -1;
          ans=max(ans,visited[i]);
        }
        return ans;
    
    
}
};