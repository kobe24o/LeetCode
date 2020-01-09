class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b) 
        	{ if(a[0] != b[0]) return a[0] < b[0]; 
        		else return a[1] < b[1];});
        int i, l = intervals[0][0], r = intervals[0][1], n = intervals.size();
        for(i = 1; i < intervals.size(); ++i)
        {
        	if(intervals[i][0] <= l && r <= intervals[i][1])
        	{
        		n--;
        		l = intervals[i][0];
        		r = intervals[i][1];
        	}
        	else if(l <= intervals[i][0] && intervals[i][1] <= r)
        		n--;
        	else
        	{
        		l = intervals[i][0];
        		r = intervals[i][1];
        	}
        }
        return n;
    }
};