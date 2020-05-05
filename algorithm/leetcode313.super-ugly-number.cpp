class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	int i, k = primes.size(), curnum = 1, temp;
    	vector<int> factor(k,1);
    	while(--n)
    	{	temp = INT_MAX;
	    	for(i = 0; i < k; ++i)
	    	{
	    		temp = min(temp, curnum*primes[i]);
	    	}
	    	for(i = 0; i < k; ++i)
	    		if(temp = curnum*primes[i])
	    			factor[i]++;
	    	curnum = temp;
		}
		return curnum;
    }
};