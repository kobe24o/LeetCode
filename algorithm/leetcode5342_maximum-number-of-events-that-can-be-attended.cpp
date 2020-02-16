class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[](vector<int>& a, vector<int>& b)
        		{
        			if(a[0] == b[0])
        				return a[1] < b[1];
        			return a[0] < b[0];
        		});
        int i, j, count = 0, attendTime = 0;
        for(i = 0; i < events.size(); ++i)
        {
        	if(attendTime < events[i][0])
        	{
        		attendTime = events[i][0];
        		count++;
        		attendTime++;
        	}
        	else if(attendTime <= events[i][1])
        	{
        		for(j = i+1; j < events.size() && events[i][1] <= events[j][1]; ++j)
        		{
        			if(attendTime < events[j][0])
        				break;
        		}
        		if(j < events.size() && attendTime >= events[j][0])
        		{
        			count++;
        			events.erase(events.begin()+j);
        			attendTime++;
        			i--;
        			continue;
        		}
                count++;
        		attendTime++;
        	}
        }
        return count;
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int,vector<int>, greater<int>> q;//小顶堆，结束时间早的，先出队
        int count = 0, i = 0, time = 0;
        while(i < events.size() || !q.empty())
        {
            time++;
            while(!q.empty() && q.top() < time)//结束时间过去了，该会议删除
                q.pop();
            while(i < events.size() && events[i][0] == time)
            {
                q.push(events[i][1]);//time时间，会议i开始了，把他的结束时间push进去
                i++;
            }
            if(!q.empty())
            {
                count++;
                q.pop();//最早结束的先参加
            }
        }
        return count;
    }
};