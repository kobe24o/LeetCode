class Solution {
    int mod = 1e9+7;
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors%3 == 0)
            return mypow(3, primeFactors/3);
        else if(primeFactors%3 == 1)
            return mypow(3, primeFactors/3-1)*4%mod;
        else
            return mypow(3, primeFactors/3-1)*2%mod;
    }
    int mypow(int base, int n)
    {
        long long ans = 1, p = base;
        while(n)
        {
            if(n&1)
                ans = (ans*p)%mod;
            p = (p*p)%mod;
            n >>= 1;
        }
        return ans;
    }
};