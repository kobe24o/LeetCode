class Solution {
public:
    int findNthDigit(int n) {
    	if(n < 10)
    		return n;
    	int count = 10, i = 2, bits = 10;
    	while(count+9*pow(10,i-1)*i <= n)
    	{
    		count += 9*pow(10,i-1)*i;
    		i++;
    	}
    	while(count+i <= n)
    	{

    	}
    }
};