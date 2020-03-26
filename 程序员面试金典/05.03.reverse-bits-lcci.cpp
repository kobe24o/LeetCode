class Solution {
public:
    int reverseBits(int num) {
    	int count = 0, maxlen = 0, prevlen = 0, i = 0, one = 1;
    	for(; i < 32; ++i)
    	{
    		if((num>>i)&1) //为1
    		{
    			count++;
    		}
    		
    	}
    }
};