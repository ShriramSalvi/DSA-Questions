class Solution {
public:
    int numberOfSpecialChars(string word) {

      unordered_map<char,int>lowercase;
      unordered_map<char,int>uppercase;

      for(int i=0; i<word.length();i++){
        char ch = word[i];
        if(ch>='a' && ch<='z')lowercase[word[i]]=i;
      else  if(ch>='A' && ch<='Z' && uppercase.find(ch)==uppercase.end())uppercase[word[i]]=i;
      }

      char lowercaseChar ='a';
      char uppercaseChar ='A';

      int count=0;

      for(int i=1; i<=26; i++){
        if(
        lowercase.find(lowercaseChar)!=lowercase.end()&&
        uppercase.find(uppercaseChar)!=uppercase.end()&&
        lowercase[lowercaseChar]<uppercase[uppercaseChar]
        )count++;
        lowercaseChar++;
        uppercaseChar++;
      }

      return count;
    }
};