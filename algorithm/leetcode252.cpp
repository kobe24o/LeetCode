class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end(),[&](auto a, auto b){
    		return a[0] < b[0];
    	});
    	for(int i = 1; i < intervals.size(); ++i)
    	{
    		if(intervals[i-1][1] > intervals[i][0])
    			return false;
    	}
    	return true;
    }
};