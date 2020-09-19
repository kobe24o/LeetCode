class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
    	int n = A.size(), i, j;
    	if(n == 1) return 1;
    	vector<long long> dp(n, 1);
    	sort(A.begin(), A.end());
    	unordered_map<int,int> m;
    	for(i = 0; i < n; i++)
    		m[A[i]] = i;
    	long long ans = 0, p, mod = 1e9+7;
    	for(i = 0; i < n; ++i)
    	{
    		for(j = 0; j <= i; ++j)
    		{
    			p = (long long)A[j]*A[i];
    			if(p > int(1e9))
    				break;
    			if(m.find(p) != m.end())
    			{
                    if(i != j)
                        dp[m[p]] += (2*dp[i]*dp[j])%mod;
                    else
                        dp[m[p]] += (dp[i]*dp[j])%mod;
                }
    		}
    	}
    	for(int i = 0; i < n; i++)
    		ans = (ans+dp[i])%mod;
    	return ans;
    }
};