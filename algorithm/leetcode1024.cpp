class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        vector<int> dp(T+1, INT_MAX);
        dp[0] = 0;
        for(int t = 0; t <= T; ++t) 
        {   //时间维度样本
            if(dp[t] == INT_MAX)
                break;//这个时间点不可到达，后续都不可能到达
            for(int i = 0; i < n; ++i)
            {   //遍历每个片段
                if(clips[i][0] <= t && t <= min(T,clips[i][1]))
                {   //该片段与时刻 t 有交集
                    for(int j = t+1; j <= min(T,clips[i][1]); ++j)
                    {   // 时刻 t 后面的可以到达
                        dp[j] = min(dp[j], dp[t]+1);
                    }
                }
            }
        }
        return dp[T]==INT_MAX ? -1 : dp[T];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(),[&](auto& a, auto& b){
            return a[0] < b[0] ||(a[0] == b[0] && a[1] < b[1]);
        });
        int ans = 0, end = 0, nt_end = 0;
        for(int i = 0; i < clips.size() && end < T; )
        {
            if(clips[i][0] > end)
                break;
            else
            {
                while(i < clips.size() 
                    && clips[i][0] <= end)
                {
                    nt_end = max(nt_end, clips[i][1]);
                    i++;
                }
                end = nt_end;
                ++ans;
            }
        }
        return end < T ? -1 : ans;
    }   
};