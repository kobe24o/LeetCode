class Solution {
public:
    double myPow(double x, int n) {
		if(n == 0) return 1.0;
		long N = n;
		if(N < 0)
		{
			x = 1/x;
			N = -N;
		}
		return POW(x, N);
    }
    double POW(double x, int N) 
    {
    	if(N == 0)	return 1.0;
    	double half = POW(x, N/2);
    	if(N%2 == 0)
    		return half*half;
    	else
    		return half*half*x;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
		if(n == 0) return 1.0;
		long N = n;
		if(N < 0)
		{
			x = 1/x;
			N = -N;
		}
		double ans=1;
		double product = x;
		for(long i = N; i; i /= 2)
		{
			if(i % 2 == 1)
				ans = ans * product;
			product = product * product;
		}
		return ans;
    }
};