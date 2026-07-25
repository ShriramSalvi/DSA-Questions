class Solution {
public:

    int minOperations(string s) {
         
    // if string starts with 0;

    int count1=0;
    bool expected = 0;
    for(int i=0; i<s.length();i++){
        if(s[i]-'0' != expected)count1++;
        expected = !expected;
    }

    // if string starts with 1

    int count2=0;
    expected =1;
   
       for(int i=0; i<s.length();i++){
        if(s[i]-'0' != expected)count2++;
        expected = !expected;
    }

    return min(count1,count2);


    }
};