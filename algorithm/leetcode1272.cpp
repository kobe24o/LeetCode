class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    	vector<vector<int>> ans;
    	int l = toBeRemoved[0], r = toBeRemoved[1];
    	for(auto& inter : intervals)
    	{
    		if(inter[1] <= l || inter[0] >= r)
    			ans.push_back(inter);
    		else//相交有两种情况
    		{
    			if(inter[0] < l)
    				ans.push_back({inter[0], l});
    			if(inter[1] > r)
    				ans.push_back({r, inter[1]});
    		}
    	}
    	return ans;
    }
};