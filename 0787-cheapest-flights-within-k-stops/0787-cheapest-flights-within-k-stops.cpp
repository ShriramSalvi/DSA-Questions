class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>distance(n,INT_MAX);

        distance[src]=0;
         k+=1;
         
        while(k--){
            
            vector<int>temp=distance;
            for(auto it:flights){
                int u=it[0];
                int v=it[1];
                int cost=it[2];



                if(distance[u]!=INT_MAX && (distance[u]+cost)<temp[v]){
                 
                    temp[v]=distance[u]+cost;
                }
            }
            distance=temp;
        }

        if(distance[dst]==INT_MAX)return -1;

        return distance[dst];
    }
};