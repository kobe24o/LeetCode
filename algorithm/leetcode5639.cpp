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
        vector<int> tot(1 << n, 0);
        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0) continue;
                int left = (i - (1 << j));
                tot[i] = tot[left] + jobs[j];
                break;
            }
        }
        
        vector<vector<int>> dp(k, vector<int>(1 << n, -1));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = tot[i];
        }
        
        for (int j = 1; j < k; j++) {
            for (int i = 0; i < (1 << n); i++) {
                int minv = INT_MAX;
                for (int s = i; s; s = (s - 1) & i) { // 枚举 i 的全部子集
                    int left = i - s;
                    int val = max(dp[j-1][left], tot[s]);
                    minv = min(minv, val);
                }
                dp[j][i] = minv;
            }
        }
        return dp[k-1][(1<<n)-1];
    }
};