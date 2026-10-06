class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses,0);

        for(auto it:prerequisites){
            indegree[it[0]]++;
            mp[it[1]].push_back(it[0]);
        }

        vector<int>ans;

        deque<int>dq;

        for(int i=0; i<indegree.size();i++){
            if(indegree[i]==0)dq.push_back(i);
        }

        while(!dq.empty()){
            int currVertex=dq.front();
            dq.pop_front();
            ans.push_back(currVertex);

            for(int i:mp[currVertex]){
                indegree[i]--;
                if(indegree[i]==0)dq.push_back(i);
            }
        }
         
        if(ans.size()!=numCourses)return {};
        return ans;
    }
};