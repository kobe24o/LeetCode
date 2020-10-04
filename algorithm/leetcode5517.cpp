typedef pair<int, int> pii;

struct cmp{
	bool operator()(pii& a, pii& b) const
	{
		return a.first > b.first;//小的结束时间（结束时间早）优先
	}
};
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    	vector<int> count(k, 0);
    	priority_queue<pii,vector<pii>,cmp> q;
    	set<int> s;//可用机器编号
    	for(int i = 0; i < k; i++) 
    		s.insert(i);//机器编号
    	int id=0, maxload = 0;
    	for(int i = 0; i < arrival.size(); i++)
    	{
    		while(!q.empty() && q.top().first <= arrival[i])
    		{	//机器结束工作时间 <= 任务到达时间
    			s.insert(q.top().second);
    			q.pop();
    		}	
    		auto it = s.lower_bound(i%k);
    		if(it != s.end())//序号大于等于 i 的空闲机器存在
    		{
    			id = *it;
    			count[id]++;
    			q.push({arrival[i]+load[i], id});//结束时间，机器编号
    			s.erase(it);
    		}
    		else if(it != s.begin())
    		{
    			id = *s.begin();
    			count[id]++;
    			q.push({arrival[i]+load[i], id});
    			s.erase(s.begin());
    		}
    		maxload = max(maxload, count[id]);
    	}
    	vector<int> ans;
    	for(int i = 0; i < k; i++)
    		if(count[i] == maxload)
    			ans.push_back(i);
    	return ans;
    }
};