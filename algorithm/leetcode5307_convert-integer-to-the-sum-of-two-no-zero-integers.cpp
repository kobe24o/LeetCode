class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n/2; i++)
        {
        	if(noZero(i) && noZero(n-i))
        		return {i, n-i};
        }
        return {};
    }

    bool noZero(int num)
    {
    	while(num)
    	{
    		if(num%10==0)
    			return false;
    		num /= 10;
    	}
    	return true;
    }
};