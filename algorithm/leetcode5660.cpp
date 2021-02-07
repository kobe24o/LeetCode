class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(),[&](auto a, auto b){
            return a[1] < b[1];//结束时间排序
        });
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // dp[i][k] 表示 遍历完 第 i 个会议，开了k次会，的最大收益
        dp[0][0] = 0;
        dp[0][1] = events[0][2];
        for(int i = 1; i < n; i++)//转移到i会议，查找之前可以转移过来的j
        {	
        	// 二分查找时间不冲突的，最晚的结束的会议 j
        	int l = 0, r = i-1, mid, j = n;
        	while(l <= r)
        	{
        		mid = l+((r-l)>>1);
        		if(events[mid][1] >= events[i][0])//时间冲突
        			r = mid-1;
        		else
        		{
        			if(mid==n-1 || events[mid+1][1] >= events[i][0])
        			{
        				j = mid;
        				break;
        			}
        			else
        				l = mid+1;
        		}
        	}
        	// i 会议不开
        	for(int t = 0; t <= k; ++t)
        		dp[i][t] = dp[i-1][t];
        	// j 可以转移到 i 会议
        	if(j == n) continue;
        	for(int t = 0; t < k; ++t)//原来开了多少次会
        	{
        		dp[i][t+1] = max(dp[i][t+1], dp[j][t]+events[i][2]);
        	}
        }
        int ans = 0;
        // for(int i = 0; i < n; i++)
	        for(int t = 0; t <= k; ++t)
	            ans = max(ans, dp[n-1][t]);
        return ans;
    }
};