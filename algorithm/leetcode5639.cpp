class Solution {
    int ans = INT_MAX;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        // 不排序 88ms
        sort(jobs.begin(), jobs.end()); // 40ms
        // sort(jobs.rbegin(), jobs.rend()); // 680ms
        vector<int> time(k, 0);
        dfs(jobs, time, k, 0);
        return ans;
    }
    void dfs(vector<int>& jobs, vector<int>& time, int k, int idx)
    {
        if(idx == jobs.size())
        {
            int t = *max_element(time.begin(), time.end());
            if(t < ans)// 最大的时间总和 更小
                ans = t;
            return;
        }
        for(int i = 0; i < k; ++i)
        {
            if(time[i]+jobs[idx] > ans)
            //如果某人的时间超过答案，不可能是更优答案，剪枝
                continue;
            time[i] += jobs[idx];
            dfs(jobs, time, k, idx+1);
            time[i] -= jobs[idx];
            if(time[i] == 0)
                break;//搜完了，不加会超时
        }
    }
};

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        // 使用 12 位二进制数的 0,1 表示某个工作分配了没
        vector<int> time(1<<n, 0);
        for(int i = 1; i < (1<<n); ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if((i & (1<<j)) == 0)
                    continue;
                int left = i - (1<<j);//除去 j 工作外的工作
                time[i] = time[left]+jobs[j];
            }
        }
        vector<vector<int>> dp(k, vector<int>(1<<n, INT_MAX));
        // dp[k][sub] 表示 前 k 个人，处理 sub 任务子集 的最优分配时间
        for(int i = 0; i < (1<<n); ++i)
            dp[0][i] = time[i];
        for(int ki = 1; ki < k; ++ki)
        {
            for(int i = 0; i < (1<<n); ++i)
            {
                for(int s = i; s; s = i&(s-1))//枚举 i 的全部子集
                {
                    int left = i - s;
                    int t = max(dp[ki-1][left], time[s]);
                    dp[ki][i] = min(dp[ki][i], t);
                }
            }
        }
        return dp[k-1][(1<<n)-1];
    }
};