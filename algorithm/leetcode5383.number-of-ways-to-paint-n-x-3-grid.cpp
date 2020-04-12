class Solution {
public:
    int numOfWays(int n) {
    	long aba = 6, abc = 6, aba_t, abc_t, mod = 1e9+7;
    	for(int i = 1; i < n; ++i)
    	{
    		aba_t = (3*aba+2*abc)%mod;
    		abc_t = (2*(aba+abc))%mod;
    		aba = aba_t;
    		abc = abc_t;
    	}
    	return (aba+abc)%mod;
    }
};