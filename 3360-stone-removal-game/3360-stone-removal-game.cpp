class Solution {
public:
    bool canAliceWin(int n) {

      int stoneToBeRemove = 10;

      bool flag = true; /// indicating alice turn;

      while(1){
       n -= stoneToBeRemove;
       if(n<0)return !flag;
       flag = !flag;
       stoneToBeRemove--;
      }

      return false;
    }
};