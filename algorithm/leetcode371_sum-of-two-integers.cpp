class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, one = 0, curBit;
        int bitA, bitB;
        for(int i = 0; i <= 31; ++i)
        {
        	bitA = a&(1<<i), bitB = b&(1<<i);
        	if(bitA^bitB == 1)
        	{
        		curBit = 1;
        		if(one)
        		{
        			curBit = 0;
        			one = 1;
        		}
        	}
        	else
        	{
        		curBit = 0;
        		if(one)
        			curBit = 1;
        		if(bitA&bitB)
        			one = 1;
        		else
        			one = 0;
        	}

        	if(curBit)
        		sum += 1<<i;
        }
        return sum;
    }
};
int main()
{
	Solution s;
	s.getSum(1,2);
}