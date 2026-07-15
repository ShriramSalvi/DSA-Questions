class Solution {
public:
    const int mod = 1000000007;
    long long factorial(int n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
        ans%=mod;
    }
    return ans;
}
    int numPrimeArrangements(int n) {
     if(n<=2)return 1;

    unordered_map<int, int>mp= {
        {2, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {11, 1},
        {13, 1},
        {17, 1},
        {19, 1},
        {23, 1},
        {29, 1},
        {31, 1},
        {37, 1},
        {41, 1},
        {43, 1},
        {47, 1},
        {53, 1},
        {59, 1},
        {61, 1},
        {67, 1},
        {71, 1},
        {73, 1},
        {79, 1},
        {83, 1},
        {89, 1},
        {97, 1}
    };
    
    int count=0;



    for(int i=1; i<=n;i++){
        if(mp.count(i))count++;
        mp[i]=count;
    }

    int even = n-mp[n];
    int odd = mp[n];

    return int(((factorial(even)%mod)*(factorial(odd)%mod))%mod);

    }
};