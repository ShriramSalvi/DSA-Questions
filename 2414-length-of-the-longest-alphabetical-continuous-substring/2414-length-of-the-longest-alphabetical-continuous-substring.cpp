class Solution {
public:
    int longestContinuousSubstring(string s) {
        
     vector<string>temp;
     
      
    for(int i=0; i<26;i++){
       
        for(int j=i; j<26;j++){
             string t="";
            for(int k=i; k<=j;k++)t.push_back(k+'a');
            temp.push_back(t);
        }
    }

   int ans=0;
   
   for(int i=0; i<temp.size();i++){
    if(s.contains(temp[i])){
        int currLen= temp[i].length();
        ans= max(ans,currLen);
    }
   }

   return ans;

   
        
    
    return ans;
    }
};