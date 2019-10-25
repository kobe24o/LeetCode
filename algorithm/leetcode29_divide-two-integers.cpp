class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
        	return INT_MAX;//溢出情况
        bool negative = (dividend>0)^(divisor>0);
        long d = abs((long)dividend);
        long dr = abs((long)divisor);
        long quotient = 0, count;
        while(d >= dr)//被除数 > 除数
        {
        	count = 0;
        	while(d >= (dr<<count))
        	{
        		count++;//乘以n次2后，不满足了
        	}
        	d -= (dr<<(count-1));//减去，除数乘以n-1次2
        	quotient += 1<<(count-1);
        }
        if(negative)
        	return -quotient;
        return quotient;
    }
};