class Solution {
public:

   string addOne(string binary) {
    int i = binary.size() - 1;

    while (i >= 0) {
        if (binary[i] == '0') {
            binary[i] = '1';
            return binary;
        }
        binary[i] = '0';
        i--;
    }

    // If all bits were 1 (e.g., "111")
    return "1" + binary;
}

    int numSteps(string s) {
      int steps=0;
      
      while(s.length()!=1){
        char lastdigit = s[s.length()-1];

        if(lastdigit == '0'){
            s.pop_back();
        }
        else{
          s = addOne(s);
        }
        steps++;
      }

      return steps;  
    }
};