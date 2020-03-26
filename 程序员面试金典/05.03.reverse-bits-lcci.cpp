class Solution {
public:
    int reverseBits(int num) {
        if(num==0)
            return 1;
    	int prevlen, prevEnd, maxlen = 0, count = 0, start=-1, curstart, curlen, curEnd;
    	map<int,pair<int,int>> continOne;
    	for(int i = 0; i < 32; ++i)
    	{
    		if((num>>i)&1) //为1
    		{
                if(start==-1)
                    start = i;
    			count++;
    			if(i == 31)
    				continOne[i] = make_pair(start,count);
    		}
    		else
    		{
    			if(count)
    				continOne[i-1] = make_pair(start,count);
    			count = 0;
                start = -1;
    		}
    	}
    	auto it = continOne.begin();
    	prevlen = it->second.second;
    	prevEnd = it->first;
    	maxlen = prevlen+1;
    	it++;
    	for(; it != continOne.end(); ++it)
    	{
            curEnd = it->first;
            curstart = it->second.first;
            curlen = it->second.second;
    		if(curstart - prevEnd == 2)
    			maxlen = max(maxlen, curlen+prevlen+1);
            else
                maxlen = max(maxlen, curlen+1);
    		prevlen = curlen;
    		prevEnd = curEnd;
    	}
        return maxlen;
    }
};

class Solution {
public:
    int reverseBits(int num) {
    	int prevlen = 0, curlen = 0, maxlen = 0;
    	for(int i = 0; i < 32; ++i)
    	{
    		if((num>>i)&1) //为1
                curlen++;
    		else
    		{
    			maxlen = max(maxlen, curlen+prevlen+1);
    			prevlen = curlen;
    			curlen = 0;
    		}
    	}
    	return maxlen;
    }
};