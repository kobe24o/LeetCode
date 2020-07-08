class Solution {
public:
    int minSwaps(vector<int>& data) {
    	int one = 0, i, j, minsp = INT_MAX;
    	for(i = 0; i < data.size(); ++i)
    	{
    		if(data[i])
    			one++;
    	}
    	i = 0; j = 0;
    	int count = 0;
    	while(j < one-1)
    	{
    		if(data[j++])
    			count++;
    	}
    	for( ; j < data.size(); ++j)
    	{
    		if(data[j])
    			count++;
    		minsp = min(minsp, one-count);
    		if(data[i++])
    			count--;
    	}
    	return minsp;
    }
};