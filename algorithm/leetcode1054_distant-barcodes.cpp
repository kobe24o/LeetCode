class Solution {
	struct cmp
	{
		bool operator()(pair<int,int>& a, pair<int,int>& b)
    	{return a.second < b.second;}//小就是大顶堆
    };
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() <= 2)
        	return barcodes;
        int n = barcodes.size(), i = 0, tpnum, tpcount;
        bool reachEnd = false;
        unordered_map<int,int> m;
        for(auto& b : barcodes)
        	m[b]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> q;
		for(auto& mi : m)
			q.push(mi);
		vector<int> ans(n,0);
		while(!q.empty())
		{
			tpnum = q.top().first;
			tpcount = q.top().second;
			q.pop();
			while(i < n && !reachEnd && tpcount)
			{
				while(i < n && tpcount)
				{
					ans[i] = tpnum;
					tpcount--;
					i += 2;
				}
				if(i >= n)
				{
					reachEnd = true;
					i = 1;//填写偶数位
				}
			}
			while(i < n && tpcount)
			{
				ans[i] = tpnum;
				tpcount--;
				i += 2;
			}
		}
		return ans;
    }
};