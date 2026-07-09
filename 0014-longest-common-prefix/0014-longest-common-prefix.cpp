class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     int idx=-1;
     int size=INT_MAX;
     for(int i=0; i<strs.size();i++){
        if(strs[i].length()<size){
            idx=i;
            size=strs[i].length();
        }
     }

     string ans=strs[idx];

     bool flag=false;

     while(!flag){
        bool flag2=false;
        for(int i=0; i<strs.size();i++){
            if(strs[i].find(ans)!=0){
                flag2=true;
                break;
            }
        }
        if(flag2)ans.pop_back();
        else break;
     }

     return ans;
    }
};