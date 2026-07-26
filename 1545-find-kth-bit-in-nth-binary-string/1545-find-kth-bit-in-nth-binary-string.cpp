class Solution {
public:
     string invertAndReverse(string s){

        // invert
        for(int i=0; i<s.length();i++){
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }
        reverse(s.begin(),s.end());

        
        return s;
     }
    char findKthBit(int n, int k) {
        
        n--;
        string s="0";
        
        while(n){
            string temp = s;
            s.push_back('1');
            s += invertAndReverse(temp);
            n--;
        }

     return s[k-1];
    }
};