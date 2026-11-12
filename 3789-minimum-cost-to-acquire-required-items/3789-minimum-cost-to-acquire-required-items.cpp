#include<algorithm>
class Solution {
public:
    long long minimumCost(int cost1_, int cost2_, int costBoth_, int need1_, int need2_) {

     long long cost1= cost1_;
     long long cost2=cost2_;
     long long costBoth=costBoth_;
     long long need1=need1_;
     long long need2=need2_;

      long long together = costBoth * max(need1,need2);
      long long indivisual=cost1*need1 + cost2*need2;
      
      long long remaining;

      if(need1>need2){
        remaining = costBoth*need2 + (need1-need2)*cost1;
      }
      else{
        remaining = costBoth*need1 + (need2-need1)*cost2;
      }
      cout<<remaining;
      return min({together,indivisual, remaining});  
    }
};