class Solution {
public:
    int maxProduct(int n) {
        int a = n%10;
        n/=10;
        
        int b = n%10;
        n/=10;
        
        
        int temp1=max(a,b);
        int temp2=min(a,b);

    

        while(n){
            if((n%10)>temp1){
                temp2 = temp1;
                temp1=n%10;
            }
            else if((n%10)>temp2){
                temp2=n%10;
            }
            n/=10;
        }

        return temp1*temp2;
    }
};