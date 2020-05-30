class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, n = intervals.size();
        int l = newInterval[0], r = newInterval[1];
        vector<vector<int>> ans;
        bool merge = false;
        for(i = 0; i < n; ++i)
        {
        	if(intervals[i][1] < l)//无交点
        		ans.push_back(intervals[i]);
        	else if(intervals[i][0] > r)//无交点
        	{
        		if(!merge)
        		{
        			ans.push_back({l,r});
        			merge = true;
        		}
        		ans.push_back(intervals[i]);
        	}
        	else
        	{
        		l = min(l, intervals[i][0]);
        		r = max(r, intervals[i][1]);
        	}
        }
        if(!merge)
        	ans.push_back({l,r});
        return ans;
    }
};