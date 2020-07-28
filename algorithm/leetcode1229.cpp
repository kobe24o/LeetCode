class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    	int m = slots1.size(), n = slots2.size(), i = 0, j = 0;
    	int l, r;
    	sort(slots1.begin(), slots1.end());
    	sort(slots2.begin(), slots2.end());
    	while(i < m && j < n)
    	{
    		if(slots1[i][1] <= slots2[j][0])
    			i++;
    		else if(slots1[i][0] >= slots2[j][1])
    			j++;
    		else
    		{
    			l = max(slots1[i][0], slots2[j][0]);
    			r = min(slots1[i][1], slots2[j][1]);
    			if(r-l >= duration)
    				return {l, l+duration};
    			if(slots1[i][1] >= slots2[j][1])
    				j++;
    			else
    				i++;
    		}
    	}
    	return {};
    }
};