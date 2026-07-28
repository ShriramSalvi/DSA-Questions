class Solution {
public:
    string smallestPalindrome(string s) {
        
           int length = s.length();
           string temp = "";

            for(int i=0; i<(length/2);i++)temp.push_back(s[i]);

            sort(temp.begin(),temp.end());
            string ans = temp;
            
            cout<<ans;
           if(length%2==1) ans.push_back(s[length/2]);

            reverse(temp.begin(),temp.end());

            ans+=temp;
            return ans;
    }
};