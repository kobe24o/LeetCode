class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    	int i, count = 0;
    	for(i = 0; i < startTime.size(); ++i)
    		if(queryTime >= startTime[i] && queryTime <= endTime[i])
    			count++;
		return count;
    }
};