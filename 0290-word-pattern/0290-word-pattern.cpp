class Solution {
public:
    bool wordPattern(string pattern, string s) {
        

        vector<string>temp;

        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;


        stringstream ss(s);

        string word;

        while(ss>>word)temp.push_back(word);

        if(temp.size()!=pattern.length())return false;

        for(int i=0; i<pattern.length();i++){
            char ch=pattern[i];
            string word = temp[i];

           if(mp1.find(word)==mp1.end() && mp2.find(ch)==mp2.end()){
            mp1[word]=ch;
            mp2[ch]=word;
           }
           else if(mp1[word]!=ch || mp2[ch]!=word)return false;
        }

        return true;
    }
};