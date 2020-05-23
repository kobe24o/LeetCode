class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
    	int l = 0, r = 0, mid, i, n = weights.size();
    	vector<int> prefixW(n);
    	for(i = 0; i < n; ++i)
    	{
    		l = max(l, weights[i]);
    		r += weights[i];
    		prefixW[i] = r;
    	}
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(canFinish(prefixW,mid,D))
    			r = mid-1;
    		else
    			l = mid+1;
    	}
    	return l;
    }
    bool canFinish(vector<int>& prefixW, int cap, int D)
    {
    	int day = 1, w = 0;
    	auto it = upper_bound(prefixW.begin(),prefixW.end(),cap);
    	while(it != prefixW.end())
    	{
    		w = *(--it)+cap;
    		it = upper_bound(prefixW.begin(),prefixW.end(),w);
    		day++;
    	}
    	return day <= D;
    }
};