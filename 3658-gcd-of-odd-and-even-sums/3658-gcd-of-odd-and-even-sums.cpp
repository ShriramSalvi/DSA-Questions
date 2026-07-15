class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int evenSum = n*(n+1);
        int oddSum = n*n;;

        int gcd=min(oddSum,evenSum);

        while(gcd){
            if(!(evenSum % gcd)&&!(oddSum%gcd))return gcd;
            gcd--;
        }

        return gcd;
    }
};