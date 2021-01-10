class Solution {
    int ans = INT_MAX;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.rbegin(), jobs.rend());
        vector<int> time(jobs.begin(), jobs.begin()+k);
        dfs(jobs, time, k, k);
        return ans;
    }
    void dfs(vector<int>& jobs, vector<int>& time, int k, int idx)
    {
        if(idx == jobs.size())
        {
            int t = *max_element(time.begin(), time.end());
            if(t < ans)
                ans = t;
            return;
        }
        for(int i = 0; i < k; ++i)
        {
            if(time[i]+jobs[idx] > ans)
                continue;
            time[i] += jobs[idx];
            dfs(jobs, time, k, idx+1);
            time[i] -= jobs[idx];
        }
    }
};