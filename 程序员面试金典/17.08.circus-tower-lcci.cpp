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
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    	int i, j, len=1, n = height.size();
    	vector<pair<int,int>> p(n);
    	for(i = 0; i < n; ++i)
    		p[i] = {height[i], weight[i]};
    	sort(p.begin(),p.end(),[](auto a, auto b){
            if(a.first==b.first)
                return a.second > b.second;
                //升高一样，降序，避免选择上升子序时把他们同时选上
            return a.first < b.first;
        });//按身高升序
    	vector<int> dp(n);
        dp[0] = p[0].second;
    	for(i = 1; i < n; ++i)
    	{
            j = bs(dp,0,len-1,len,p[i].second);//二分查找求体重的最长上升子序
            dp[j] = p[i].second;
            if(j == len)
                len++;
    	}
    	return len;
    }
    int bs(vector<int>& dp, int l, int r, int len, int target)
    {   //第一个 大于等于 我的
        int mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(dp[mid] >= target)
            {
                if(mid==0 || dp[mid-1] < target)
                    return mid;
                else
                    r = mid-1;
            }
            else// if(dp[mid] < target)
                l = mid+1;
        }
        return len;//没有找打，说明它是最大的
    }
};