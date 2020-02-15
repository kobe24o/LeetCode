class Solution {//超时，0.00001，2147483647
	unordered_map<int ,double> m;
public:
    double myPow(double x, int n) {
        if(n == 0)
        	return 1.0;
        long N = n;
        if(n < 0)
        {
        	x = 1/x;
        	N = -(long)n;//INT_MIN换号后溢出
        }
        return MyP(x, N);
    }

    double MyP(double x, long N) 
    {
    	if(N == 0)
    		return 1.0;
    	else if(N == 1)
    		return x;
    	if(N%2 == 0)
    	{
    		if(m.count(N))
    			return m[N];
    		double a = MyP(x, N/2)*MyP(x, N/2);
    		m[N] = a;
    		return a;
    	}
    	else
    	{
    		if(m.count(N))
    			return m[N];
    		double b = MyP(x, N/2)*MyP(x, N/2)*x;
    		m[N] = b;
    		return b;
    	}
    }
};

class Solution {//超时，0.00001，2147483647
	unordered_map<int ,double> m;
public:
    double myPow(double x, int n) {
        if(n == 0)
        	return 1.0;
        long N = n;
        if(n < 0)
        {
        	x = 1/x;
        	N = -(long)n;//INT_MIN换号后溢出
        }
        double ans = 1.0, product = x;
        for( ; N; N /= 2)
        {
        	if(N%2 == 1)
        		ans *= product;
        	product *= product;
        }
        return ans;
    }
};