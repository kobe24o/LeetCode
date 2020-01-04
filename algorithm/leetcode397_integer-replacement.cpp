class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
        	return 0;
        if(n == 2147483647)
            return 32;
        if(n%2 == 0)
        	return 1+integerReplacement(n>>1);
        else
        	return 1+min(integerReplacement(n+1), integerReplacement(n-1));
    }
};

class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        if(n == INT_MAX)
            return 32;
        while(n != 1)
        {
        	if((n&1) == 0)//偶数
        	{
        		++count;
        		n >>= 1;
        	}
        	else//奇数有两种情况0b01, 0b11
        	{
        		if(n == 3)//特殊情况
        		{
        			count += 2;
        			break;
        		}
        		if((n&3) == 3)
        			n += 1;//操作后可以多除1次2
        		else
        			n -= 1;
        		++count;
        	}
        }
        return count;
    }
};