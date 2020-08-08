class Solution {
public:
    int smallestFactorization(int a) {
    	long long ans = 0, base = 1;
        for(int i = 9; i >= 2; --i)
        {
        	while(a%i == 0)
        	{
        		ans += (a%i)*base;
        		base *= 10;
        		if(a > INT_MAX)
        			return 0;
        	}
        }
        return ans;
    }
};