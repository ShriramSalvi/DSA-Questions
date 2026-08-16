class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
         sort(prices.begin(),prices.end());
         sort(discounts.begin(),discounts.end());

         int left = prices.size()-1;
         int right = discounts.size()-1;
         
         double ans =0;

         while(left>=0 && right>=0){
             double p = prices[left];
             double d = discounts[right];
             ans += (p*(100-d))/100;
           
             left--;
             right--;
         }

         while(left>=0){
            ans+=prices[left];
            left--;
         }

         return ans;
    }
};