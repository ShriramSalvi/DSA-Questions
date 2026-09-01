class Solution {
public:
    int maxVowels(string s, int k) {
        

        int left=0;
        int right=0;
        
        int ans=0;
        int vowel=0;
        while(right<k){
            char ch = s[right];

            if(ch == 'a' || ch =='e' || ch=='i'||
               ch =='o' || ch=='u'
            )vowel++;

            right++;
        }


        while(right<s.length()){
            ans = max(ans,vowel);
            
            char add = s[right];
          
          if(add=='a' || add=='e' || add =='i'||
            add=='o' || add =='u'
          )vowel++;

          char remove = s[left];
           
          if(remove =='a' || remove =='e' || remove =='i'||
            remove =='o' || remove =='u'
          )vowel--;

          left++;
          right++;
        }
       
          ans = max(ans,vowel);
        return ans;
    }
};