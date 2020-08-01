class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
    	vector<vector<int>> v;
    	int k = nums.size();
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		for(int n : nums[i])
    			v.push_back({n,i});
    	}
    	sort(v.begin(), v.end());
    	unordered_map<int,int> m;//区间编号，该区间有多少个数在窗口内
    	int i = 0, j = 0, n = v.size();
    	int l = -1e7, r = 1e7, minlen = INT_MAX;
    	while(j < n)
    	{
    		if(m.size() < k)
    		{
    			m[v[j][1]]++;
    		}
    		while(m.size() == k)
    		{
    			if(v[j][0]-v[i][0] < r-l)
    			{
    				l = v[i][0];
    				r = v[j][0];
    			}
    			if(--m[v[i][1]] == 0)
    				m.erase(v[i][1]);
    			i++;
    		}
            j++;
    	}
    	return {l, r};
    }
};