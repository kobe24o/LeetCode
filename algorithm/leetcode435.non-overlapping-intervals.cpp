class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	if(intervals.empty()) return 0;
    	sort(intervals.begin(), intervals.end(),[&](auto a, auto b){
    		return a[1] < b[1];
    	});
    	int i, count = 1, n = intervals.size();
        vector<int> prev(intervals[0]);
    	for(i = 1; i < n; ++i)
    	{
    		if(prev[1] <= intervals[i][0])
    		{
    			count++;
    			prev = intervals[i];
    		}
    	}
    	return n-count;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),[&](auto a, auto b){
    		return a[0] < b[0];
    	});
    	vector<int> dp(intervals.size(),1);
        int i, j, maxlen = 1;
        for(i = 1; i < intervals.size(); ++i)
        {
            j = i-1;
            while(j>=0 && intervals[j][1] > intervals[i][0])
                j--;
            if(j >= 0)
                dp[i] = max(dp[i], dp[j]+1);
            maxlen = max(maxlen, dp[i]);
        }
        return intervals.size()-maxlen;
    }
};