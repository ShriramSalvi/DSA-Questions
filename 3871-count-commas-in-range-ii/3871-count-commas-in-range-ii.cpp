class Solution {
public:
    long long countCommas(long long n) {
        
        if(n<=999)return 0;

        if(n< 1000000)return n-1000+1;

        if(n<1000000000){
            long long ans =0;
            // for below 1000000 one comma
            ans += 999999-1000+1;

            // for below 1000000000

            ans+= (n-1000000+1)*2;
            return ans;
        }

        if(n<1000000000000){
            long long ans=0;
            // for below 1000000 one comma
            ans += 999999-1000+1;


            // for below 10^9
             ans+= (999999999-1000000+1)*2;

            // for below 10^12

            ans+= (n-1000000000+1)*3;
            
            return ans;

        }

      if(n<1000000000000000){
        long long ans =0;

           // for below 10^6 one comma
            ans += 999999-1000+1;


             // for below 10^9
             ans+= (999999999-1000000+1)*2;

             // for below 10^12

             ans+= (999999999999-1000000000+1)*3;

             // below 10^15

             ans+=(n-1000000000000+1)*4;
             return ans;


      }

     // for 10 ^15
     
     return 3998998998999005;

    }
};