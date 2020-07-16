class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
    	int i;
    	set<int> s;
    	s.insert(bulbs[0]);
    	for(i = 1; i < bulbs.size(); i++)
    	{
    		auto p = s.insert(bulbs[i]);
    		auto it = p.first, end = p.first;
    		if(p.first != s.begin())
    		{
    			if(abs(*(--it)-bulbs[i])==k+1)
    				return i+1;
    		}
    		it = p.first, end = --s.end();
    		if(p.first != end)
    		{
    			if(abs(*(++it)-bulbs[i])==k+1)
    				return i+1;
    		}
    	}
    	return -1;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int i, l = 0, r = k+1, d = INT_MAX;
        vector<int> day(bulbs.size());
        for(i = 0; i < bulbs.size(); i++)
            day[bulbs[i]-1] = i+1;
        i = 1;
        while(r < bulbs.size())
        {
            if(day[l] < day[i] && day[i] > day[r])
            {
                i++;//这天比端点都晚开花
                continue;
            }
            if(i == r)
                d = min(d, max(day[l], day[r]));//求最早的那天
            //不满足，从i开启新的窗口
            l = i;
            r = i+k+1;
            i++;
        }
        return d==INT_MAX ? -1 : d;
    }
};