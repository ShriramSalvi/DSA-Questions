class Solution {
public:
    bool checkString(string s) {
      
      auto it = s.find("ba");

      if(it == string::npos)return true;
      return false;
    }
};