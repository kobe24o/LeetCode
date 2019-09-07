class Solution {
public:
    int numPrimeArrangements(int n) {
        if(n == 1)
        	return 1;
        int count = 0, i, j, ans = 1;
        for(i = 2; i <= n; ++i)
        {
        	for(j = 2; j <= sqrt(i); ++j)
        	{
        		if(n%j == 0)
        			break;
        	}
        	++count;
        }
        n = n-count;
        while(n--)
        	ans *= n;
        while(count--)
        	ans *= count;
        return ans;
    }
};