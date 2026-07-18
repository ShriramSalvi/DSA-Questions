class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;

        vector<int>s1count(26,0);
        vector<int>s2count(26,0);
        
        for(char ch:s1)s1count[ch-'a']++;
        int left =0;
        int right=0;

        while(right<s1.length()){
            s2count[s2[right]-'a']++;
            right++;
        }

        while(right<s2.length()){
            bool flag=true;
            for(int i=0; i<26; i++)if(s1count[i]!=s2count[i]){flag=false; break;}
            if(flag)return true;

            s2count[s2[left]-'a']--;
            left++;
            s2count[s2[right]-'a']++;
            right++;
        }

            bool flag=true;
            for(int i=0; i<26; i++)if(s1count[i]!=s2count[i]){flag=false; break;}
            if(flag)return true;

            return false;
    }
};