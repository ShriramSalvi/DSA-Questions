class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length())return {};
        vector<int>pcount(26,0);
        vector<int>scount(26,0);

        for(char ch:p)pcount[ch-'a']++;
        
    
        int windowSize=p.length();
        int left=0;
        int right=0;

        while(right<windowSize){
            scount[s[right]-'a']++;
            right++;
        }
        
        vector<int>ans;
        while(right<s.length()){
            bool flag = true;
            for(int i=0; i<26;i++)if(pcount[i]!=scount[i]){flag=false;break;}

            if(flag)ans.push_back(left);

            scount[s[left]-'a']--;
            left++;
            scount[s[right]-'a']++;
            right++;
        }

        bool flag = true;
        for(int i=0; i<26;i++)if(pcount[i]!=scount[i]){flag=false;break;}
        if(flag)ans.push_back(left);

        return ans;
    }
};