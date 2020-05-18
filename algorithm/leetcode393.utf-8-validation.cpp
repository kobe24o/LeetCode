class Solution {
public:
    bool validUtf8(vector<int>& data) {
    	int i = 0, j, one = 0, n = data.size();
    	while(i < n)
    	{
    		for(j = 7; j >= 0; --j)
    		{
    			if((data[i]&(1<<j)))//为1
    				one++;
    			else
    				break;
    		}
    		if(one==1 || one > 4)
    			return false;
    		i++;
    		if(one == 0)
    			continue;
    		if(n-i < one-1) return false;
	    	for( ; i < n && (--one); ++i)
	    	{
	    		if(((data[i]>>7)&1)!=1 || ((data[i]>>6)&1)!=0)
	    			return false;
	    	}
    	}
    	return true;
    }
};