class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    	map<int,int> m;//难度，该难度及以下，收益最高的工作
    	for(int i = 0; i < difficulty.size(); ++i)
    		m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
    	int maxprofit = -1, ans = 0;
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		maxprofit = max(maxprofit, it->second);
    		it->second = maxprofit;
    	}
    	for(int i = 0; i < worker.size(); ++i)
    	{
            auto it = m.upper_bound(worker[i]);
            if(it != m.begin())
                ans += (--it)->second;
        }
    	return ans;
    }
};