class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
    	vector<int> ans(rains.size(), -1);
    	unordered_map<int,int> laker;//要抽水的湖泊数字, 对应的天idx
    	deque<int> q;//可以抽水的天的编号idx
    	for(int i = 0; i < rains.size(); ++i)
    	{
    		if(rains[i])//打雷了，下雨了，rains[i]号填满了
    		{
    			if(laker.find(rains[i]) == laker.end())
    				laker[rains[i]] = i;
    			else//今天要下雨，这个湖有水，危险，我们要找之前的一天抽水
    			{
    				int n = q.size();
    				while(n-- && laker[rains[i]] > q.front())
    				{	//下雨的日期在可以抽水之后，干不了活
    					q.push_back(q.front());
    					q.pop_front();
    				}
    				if(q.empty() || laker[rains[i]] > q.front())//没有可以抽的时间
    					return {};//over
    				else
    				{
    					ans[q.front()] = rains[i];
    					q.pop_front();
    					laker[rains[i]] = i;//湖抽干了，今天的水可以放下
    				}
    			}
    		}
    		else//没有下雨，可以抽水
    			q.push_back(i);
    	}
    	while(!q.empty())//没有干活的天数，填上任意数字1-10e9
    	{
    		ans[q.front()] = 24;
    		q.pop_front();
    	}
    	return ans;
    }
};
//[0,1,1]