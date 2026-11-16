class Solution {
public:
    string helper(string s, int k){
        string temp;
        for(int i=0; i<s.length();i+=k){
            int sum=0;
            int j=i;
            while(j<s.length() && j<(i+k)){
                sum+= s[j]-'0';
                j++;
            }
           
            temp+= to_string(sum);
            
        }
        
        return temp;
    }
    string digitSum(string s, int k) {
        
        while(s.length()>k){
            s=helper(s,k);
        }
        return s;
    }
};