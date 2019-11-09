class Solution {
public:
    bool judgeSquareSum(int c) {
        long  i = 0, j = pow(c, 0.5)+1, val = 0;
        while(i <= j)
        {
        	val = i*i+j*j;
        	if(val < c)
        		i++;
        	else if(val > c)
        		j--;
        	else
        		return true;
        }
        return false;
    }
};