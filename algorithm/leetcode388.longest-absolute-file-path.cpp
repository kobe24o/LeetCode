class Solution {
public:
    int lengthLongestPath(string input) {
    	int maxlen=0, i, lv = 0, count=0;
    	vector<int> len(50,0);
    	bool foundfile = false;
    	for(i = 0; i < input.size(); ++i)
    	{
    		if(input[i]=='\n')
    		{
    			len[lv] = lv>0 ? len[lv-1]+count : count;
    			if(foundfile)
    			{
    				maxlen = max(maxlen, len[lv]+lv);
    				foundfile = false;
    			}
    			lv = 0;
    			count = 0;
    		}
    		else if(input[i]=='\t')
    			lv++;
    		else
    		{
    			if(i>0 && input[i-1]=='.' && (isalpha(input[i])||isdigit(input[i])))
    				foundfile = true;
    			count++;
    		}
    	}
        len[lv] = lv>0 ? len[lv-1]+count : count;
        if(foundfile)
        {
            maxlen = max(maxlen, len[lv]+lv);
            foundfile = false;
        }
    	return maxlen;
    }
};