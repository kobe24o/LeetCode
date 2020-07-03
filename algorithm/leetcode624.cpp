class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    	int i, j, maxdis = 0, n = arrays.size();
    	for(i = 0; i < n; ++i)
    	{
    		for(j = i+1; j < n; ++j)
    		{
    			maxdis = max(maxdis, abs(arrays[i].front()-arrays[j].back()));
    			maxdis = max(maxdis, abs(arrays[j].front()-arrays[i].back()));
    		}
    	}
    	return maxdis;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    	int i, j, maxdis = 0, n = arrays.size();
        int MAX = arrays[0].back(), MIN = arrays[0].front();
    	for(i = 1; i < n; ++i)
    	{
    		maxdis = max(maxdis, abs(arrays[i].front()-MAX));
            maxdis = max(maxdis, abs(arrays[i].back()-MIN));
            MIN = min(MIN, arrays[i].front());
            MAX = max(MAX, arrays[i].back());
    	}
    	return maxdis;
    }
};