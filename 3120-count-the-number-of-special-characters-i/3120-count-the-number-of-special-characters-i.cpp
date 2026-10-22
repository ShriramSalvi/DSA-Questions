class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        char lowercase = 'a';
        char uppercase = 'A';
        
        int count=0;
        for(int i=1; i<=26; i++){
            if(word.find(lowercase)!=string::npos && word.find(uppercase)!=string::npos)count++;
            lowercase++;
            uppercase++;
        }

        return count;
    }
};