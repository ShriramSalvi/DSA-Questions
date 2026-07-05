class Solution {
public:
    int decimalConverter(string s){
        int  ans=0;
        int  powerOf2=1;

        for(int i=s.size()-1;i>=0;i--){
           ans = ans + (s[i]-'0') * powerOf2;
            powerOf2 *= 2;
        } 

        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int>mp;

        for(string s: nums)mp[decimalConverter(s)]++;

        
        int temp=0;
        for(int i=0;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                temp=i;
                break;
            }
        }

        // converting temp to binary;
        
         string ans="";
  

        while(temp){
            ans.push_back((temp%2)+'0');
            temp/=2;
        }

        if(ans.length() != nums.size()) while(ans.length()!=nums.size())ans.push_back('0');
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};