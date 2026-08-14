class Solution {
    public int maximumLengthSubstring(String s) {
        
        int left=0;
        int right=0;

        int [] temp = new int[26];

        int size = s.length();

        int length =0;


        while(right < size){
          
          temp[s.charAt(right)-'a']++;

          if(temp[s.charAt(right)-'a']>2){
           length = Math.max((right-left),length); // calculating ans;

           while(temp[s.charAt(right)-'a']!=2){
             // reducing frequency till freq becomes 2
             temp[s.charAt(left)-'a']--;
             left++;
           }
          }
           right++;
        }
        length = Math.max((right-left),length);
       return length;
    }
}