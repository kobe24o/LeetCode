class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    	int i, j, n = height.size(),maxP = 1;
    	vector<vector<int>> p(n);
    	for(i = 0; i < n; ++i)
    		p[i] = {height[i], weight[i]};
    	sort(p.begin(),p.end());//按身高升序
    	vector<int> dp(n,1);
    	for(i = 1; i < n; ++i)
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			if(p[i][1] > p[j][1])
    			{
    				dp[j] = max(dp[j], 1+dp[i]);
    				maxP = max(maxP, dp[j]);
    			}
    		}
    	}
    	sort(p.begin(),p.end(),[&](auto a, auto b){
    		return a[1] < b[1];
    	});//按体重升序
    	dp.resize(n,1);
    	for(i = 1; i < n; ++i)
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			if(p[i][0] > p[j][0])
    			{
    				dp[j] = max(dp[j], 1+dp[i]);
    				maxP = max(maxP, dp[j]);
    			}
    		}
    	}
    	return maxP;
    }
};
struct cmp1{
	bool operator()(const& a, const& b)
	{
		if(a[0]==b[0])
			return a[1] < b[1];
		return a[0] < b[0];
	}
};
struct cmp2{
	bool operator()(const& a, const& b)
	{
		if(a[1]==b[1])
			return a[0] < b[0];
		return a[1] < b[1];
	}
};
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    	int i, j, n = height.size(),maxP = 1;
    	vector<vector<int>> p(n);
    	for(i = 0; i < n; ++i)
    		p[i] = {height[i], weight[i]};
 		set<vector<int>,cmp1> dp1;
 		set<vector<int>,cmp1> dp2;
    	for(i = 0; i < n; ++i)
    	{
    		auto it = dp1.upper_bound(p[i]);
    		if(it == dp1.end())
    			dp1.insert(p[i]);
    		else
    		{	
    			dp1.erase(it);
    			dp1.insert(p[i]);
    		}
    	}
		for(i = 0; i < n; ++i)
    	{
    		auto it = dp2.upper_bound(p[i]);
    		if(it == dp2.end())
    			dp2.insert(p[i]);
    		else
    		{	
    			dp2.erase(it);
    			dp2.insert(p[i]);
    		}
    	}
    	return max(dp1.size(),dp2.size());
    }
};
