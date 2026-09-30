class Solution {
public:
    int isPalindrom(int left,int right,string & s){
        

        while(left<=right){
            if(s[left]!=s[right]){
                return 0;
            }
            left++;
            right--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0; i<s.length();i++){
        
        for(int j=i; j<s.length();j++){
            
                count+=isPalindrom(i,j,s);
            
        }
        }

        return count;

    }
};