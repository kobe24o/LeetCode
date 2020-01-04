class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // if(duration == 0)
        // 	return 0;
        int time = 0, endtime;
        for(int i = 0; i < timeSeries.size(); ++i)
        {
        	endtime = timeSeries[i] + duration;
        	if(i == timeSeries.size()-1 || endtime <= timeSeries[i+1])
	        	time += duration;
	        else
	        {
	        	time += timeSeries[i+1]-timeSeries[i];
	        }
        }
        return time;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
        	return 0;
        int time = 0;
        for(int i = 0; i < timeSeries.size()-1; ++i)
        	time += min(timeSeries[i+1]-timeSeries[i], duration);
        return time+duration;
    }
};