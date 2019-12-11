class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int mins[1440] = {0};
        int m, i;
        for(auto& s : timePoints)
        {
        	m = ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
        	if(mins[m] != 0)
        		return 0;
        	mins[m] = 1;
        }
        int first, prev, last, ans = 1440;
        for(i = 0; i < 1440 && mins[i] == 0; i++){}
    	first = prev = i++;
    	for( ; i < 1440; ++i)
    	{
    		if(mins[i] == 1)
    		{
    			last = i;
    			ans = min(ans, last-prev);
    			prev = last;
    		}
    	}
    	return min(ans, first-last+1440);
    }
};