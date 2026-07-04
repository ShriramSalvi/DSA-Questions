class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;

        for(int i=0; i<words.size();i++){
            bool flag = false;
            for(int j=0;j<words.size();j++){
                if(j!=i && words[j].length()>=words[i].length() && words[j].contains(words[i])){
                    flag = true;
                    break;
                }
            }
            if(flag)ans.push_back(words[i]);
        }

        return ans;
    }
};