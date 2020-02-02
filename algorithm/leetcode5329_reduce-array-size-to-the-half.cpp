class Solution {
public:
    int minSetSize(vector<int>& arr) {
    	map<int,int> m;
        for(auto& a : arr)
    		m[a]++;
    	priority_queue<int> q;
    	for(auto& it : m)
    		q.push(it.second);//个数
    	int target = arr.size()/2, count = 0, n = 0;
    	while(count < target)
    	{
    		count += q.top();
    		n++;
    		q.pop();
    	}
    	return n;
    }
};