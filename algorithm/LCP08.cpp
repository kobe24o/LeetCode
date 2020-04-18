struct cmp1
{
	bool operator()(const vector<int>& a, const vector<int>& b)const
	{
		if(a[0]==b[0])
		{
			if(a[1]==b[1])
				return a[2] < b[2];
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
};

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& inc, vector<vector<int>>& req) {
    	int t = 0, n = req.size(), a = 0, b = 0, c =0;
    	vector<int> ans(n,-1);
    	map<vector<int>, int> m;
    	set<vector<int>,cmp1> set1;
    	for(int i = 0; i < n; ++i)
    	{
    		m[req[i]]=i;
    		set1.insert(req[i]);
    	}

    	vector<int> ok;
    	vector<int> tp;
    	auto end1 = set1.upper_bound({a,b,c});
		for(auto it = set1.begin(); it != end1; ++it)
		{
			tp = *it;
			if(a>=tp[0] && b>=tp[1] && c>=tp[2])
			{
    			ans[m[tp]] = t;
    			set1.erase(tp);
    		}
		}
    	for(int i = 0; i < inc.size(); ++i)
    	{
    		t = i+1;
    		a += inc[i][0];
    		b += inc[i][1];
    		c += inc[i][2];
    		ok.clear();
    		auto end = set1.upper_bound({a,b,c});
    		for(auto it = set1.begin(); it != end; ++it)
    		{
    			tp = *it;
    			if(a>=tp[0] && b>=tp[1] && c>=tp[2])
    			{
	    			ans[m[tp]] = t;
	    			set1.erase(tp);
	    		}
    		}
    	}
    	return ans;
    }
};