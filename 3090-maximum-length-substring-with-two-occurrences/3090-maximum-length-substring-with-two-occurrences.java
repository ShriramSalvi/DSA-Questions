class Solution {
    public int maximumLengthSubstring(String s) {


       int []arr= new int[26];   // Frequency array

       int left=0;
       int right=0;
       int ans=0;

       while(right<s.length()){
         
         arr[s.charAt(right)-'a']++;

         if(arr[s.charAt(right)-'a']>2){
           
           ans = Math.max(ans,right-left);

           while(arr[s.charAt(right)-'a']>2){
            arr[s.charAt(left)-'a']--;
            left++;
           }
         }
         right++;
       }
       ans = Math.max(ans,right-left);
       return ans;
    }
}