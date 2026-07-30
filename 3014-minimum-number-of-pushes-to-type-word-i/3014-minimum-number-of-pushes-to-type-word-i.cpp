class Solution {
public:
    int minimumPushes(string word) {

      if(word.length()<=8)return word.length();

      if(word.length()<=16){
        int more = word.length()-8;
        return 8+more*2;
      } 

      if(word.length()<=24){
        int more = word.length()-16;
       return 8+16+more*3;
      }

      int more = word.length()-24;

      return 8+16+24+more*4;
    }
};