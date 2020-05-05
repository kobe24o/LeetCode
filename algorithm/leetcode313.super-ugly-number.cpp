class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	int i, j, k = primes.size();
    	vector<long> idx(k,1);
        vector<long long> dp(n+1, LONG_LONG_MAX);
        dp[1] = 1;
    	for(i = 2; i <= n; ++i)
    	{	
	    	for(j = 0; j < k; ++j)
                if(dp[idx[j]]*primes[j] < dp[i])
                    dp[i] = dp[idx[j]]*primes[j];
	    	for(j = 0; j < k; ++j)
	    		if(dp[i] == dp[idx[j]]*primes[j])
	    			idx[j]++;
		}
		return dp[n];
    }
};