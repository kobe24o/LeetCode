class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
    	vector<priority_queue<int>> countUse(20001);//
    	for(int i = 0; i < values.size(); ++i)
    		countUse[labels[i]].push(values[i]);
    	int k, sum = 0;
    	priority_queue<int> q;
    	for(int i = 0; i <= 20000; ++i)
    	{
    		k = use_limit;
    		while(k-- && !countUse[i].empty())
    		{
    			q.push(countUse[i].top());
    			countUse[i].pop();
    		}
    	}
    	while(num_wanted-- && !q.empty())
    	{
    		sum += q.top();
    		q.pop();
    	}
    	return sum;
    }
};