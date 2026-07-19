class Solution {
public:
    string removeDuplicateLetters(string s) {
                vector<int>rightMostOccurance(26,0);
        vector<bool>visited(26,0);

     for(int i=s.length()-1;i>=0; i--)
     if(rightMostOccurance[s[i]-'a']<i)rightMostOccurance[s[i]-'a']=i;

     for(int i:rightMostOccurance)cout<<i<<" ";

     string ans="";

     for(int i=0; i<s.length();i++){
        if(visited[s[i]-'a'])
        continue;
       
       while(
       ans.length()!=0 
       && s[i]<ans[ans.length()-1]
       && rightMostOccurance[ans[ans.length()-1]-'a']>i
       ){
        visited[ans[ans.length()-1]-'a']=false;
        ans.pop_back();
       };
       
       if(!visited[s[i]-'a'])
       {
        ans.push_back(s[i]);
        visited[s[i]-'a']=true;
       }
       
     }

     return ans;
    }
};