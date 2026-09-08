class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        for(int i = 1000; i <= n; i++){
            int num = i;
            while(num != 0){
                num = num % 10;
                cnt++;
                num /= 10;
            }
        }
        return cnt;
    }
};