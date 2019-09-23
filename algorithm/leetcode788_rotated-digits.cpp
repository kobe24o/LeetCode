class Solution {
public:
    int rotatedDigits(int N) {
    	int i, num, bit, count = 0;
    	bool flag, includeDiffer;
        for(i = 2; i <= N; ++i)
        {
        	num = i;
        	flag = true;
        	includeDiffer = false;
        	while(num)
        	{
        		bit = num % 10;
        		if(bit == 3 || bit == 4 || bit == 7)
        		{
        			flag = false;
        			break;
        		}
        		if(includeDiffer == false && (bit == 2 || bit == 5 || bit == 6 || bit == 9))
        			includeDiffer = true;
        		num /= 10;
        	}
        	if(flag && includeDiffer)
        		++count;
        }
        return count;
    }
};