class Solution {
public:
    int preimageSizeFZF(int K) {
        return binsearch(K+1)-binsearch(K);
    }

    int tail0count(long n)
    {
    	int count = 0;
    	while(n)
    	{
    		count += n/5;
    		n /= 5;
    	}
    	return count;
    }
    int binsearch(int K)//查找阶乘有K个0的最小数
    {
    	long l = 0, r = 1e10, mid, count0;
        while(l < r)
        {
        	mid = l+((r-l)>>1);
        	count0 = tail0count(mid);
        	if(count0 < K)
        		l = mid+1;
        	else// if(count0 >= K)
        		r = mid;
        }
        return l;
    }
};