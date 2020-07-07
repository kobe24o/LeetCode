class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    	if(intervals.empty()) return 0;
    	sort(intervals.begin(), intervals.end(),[&](auto a, auto b){
    		if(a[0] == b[0])
    			return a[1] < b[1];//开始时间一样，先结束的在前
    		return a[0] < b[0];//开始早的在前
    	});
    	priority_queue<int,vector<int>,greater<int>> q;//小顶堆,存放会议室结束时间，小的在上
    	q.push(intervals[0][1]);
    	for(int i = 1; i < intervals.size(); ++i)
    	{
    		if(intervals[i][0] >= q.top())//最早结束的会议室可用，占用它
    		{
    			q.pop();
    		}
    		q.push(intervals[i][1]);
    	}
    	return q.size();
    }
};