class Solution {
public:
	static bool comp(vector<int> &a, vector<int> &b)
	{
		return a[0] <= b[0];
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	if(intervals.empty())
    		return {};
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i)
        {   
        	if(intervals[i][0] <= right)
        		right = max(right, intervals[i][1]);
        	else
        	{
        		ans.push_back({left,right});
        		left = intervals[i][0];
        		right = intervals[i][1];
        	}
        }
        ans.push_back({left,right});
        return ans;
    }
};