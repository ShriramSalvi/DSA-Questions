class Solution {
public:
    bool helper(int n,int &t){

        int product=1;

        while(n){
            int digit = n%10;
            n/=10;
            product*=digit;
        }

        return product%t == 0;
    }
    int smallestNumber(int n, int t) {
        
        while(!helper(n,t))n+=1;

        return n;
    }
};