class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int num:nums)
        	m[num]++;
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(),
        		[](pair<int,int> &a, pair<int,int> &b)
        		{return a.second > b.second;});
        auto it = v.begin();
        while(k--)
        {
        	ans.push_back(it->first);
        	++it;
        }
        return ans;
    }
};


class Solution {
	struct cmp//必须写struct，不能写class
	{
		bool operator()(pair<int, int>& a, pair<int, int>& b)
		{ return a.second > b.second; }//小顶堆
	};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int num:nums)
        	m[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;
        for(auto a:m)
        {
        	q.push(a);
        	if(q.size() > k)
        		q.pop();
        }
        while(!q.empty())
        {
        	ans.push_back(q.top().first);
        	q.pop();
        }
        return ans;
    }
};