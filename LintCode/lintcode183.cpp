class Solution {
public:
    int woodCut(vector<int> &L, int k) {
        if(L.empty())
            return 0;
        sort(L.begin(),L.end());
        int l1 = 1, l2 = L.back(), lm, maxlen = 0;
        while(l1 <= l2)
        {
        	lm = l1+((l2-l1)>>1);
        	if(count(L,lm) >= k)
        	{
        		maxlen = max(maxlen, lm);
        		l1 = lm+1;
        	}
        	else
        		l2 = lm-1;
        }
        return maxlen;
    }

    int count(vector<int> &L, int& l)
    {	//计算可以得到l长度的木头多少根
    	int c = 0;
    	for(auto& Li : L)
    		c += Li/l;
    	return c;
    }
};