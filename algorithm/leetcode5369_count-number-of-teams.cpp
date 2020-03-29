class Solution {
public:
    int numTeams(vector<int>& rating) {
    	int i, j, k, sum = 0, n = rating.size();
    	for(i = 0; i < n-2; ++i)
    		for(j = i+1; j < n-1; ++j)
    			for(k = j+1; k < n; ++k)
    				if((rating[i] < rating[j] && rating[j] < rating[k])
    					 ||(rating[i] > rating[j] && rating[j] > rating[k]))
    					sum++;
    	return sum;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
    	int i, j, lsmall, lLarge, rsmall, rLarge, sum = 0, n = rating.size();
    	for(i = 1; i < n-1; ++i)
    	{
    		lsmall = lLarge = rsmall = rLarge = 0;
    		for(j = 0; j < i; ++j)
    		{
    			if(rating[j] < rating[i])
    				lsmall++;
    			if(rating[j] > rating[i])
    				lLarge++;
    		}
    		for(j = i+1; j < n; ++j)
    		{
    			if(rating[j] < rating[i])
    				rsmall++;
    			if(rating[j] > rating[i])
    				rLarge++;
    		}
    		sum += lsmall*rLarge + lLarge*rsmall;
    	}
    	return sum;
    }
};