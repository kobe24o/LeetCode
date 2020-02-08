class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)
            return 0;
        int i, tp, prev = arr[0];
        const int n = arr.size();
        vector<int> dp(n, INT_MAX);
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = true;
        dp[0] = 0;
        multimap<int, int> m;
        for(i = 0; i < n; i++)
        {
            if(arr[i] == prev)
                continue;
            else
            {
                m.insert(make_pair(prev, i-1));
                prev = arr[i];
            }
        }
        m.insert(make_pair(arr[n-1],n-1));
        while(!q.empty() && (dp[n-1] == INT_MAX))
        {
            tp = q.front();
            q.pop();
            if(tp+1 < n && !visited[tp+1])
            {
                dp[tp+1] = min(dp[tp+1], 1+dp[tp]);
                q.push(tp+1);
                visited[tp+1] = true;
            }
            if(tp-1>0 && !visited[tp-1])
            {
                dp[tp-1] = min(dp[tp-1], 1+dp[tp]);
                q.push(tp-1);
                visited[tp-1] = true;
            }
            if(dp[n-1] != INT_MAX)
                return dp[n-1];
            auto start = m.equal_range(arr[tp]).first, end = m.equal_range(arr[tp]).second;
            for(auto it = start; it != end; ++it)
            {
                if(!visited[it->second])
                {
                    visited[it->second] = true;
                    dp[it->second] = min(dp[it->second], 1+dp[tp]);
                    q.push(it->second);
                }
                if(dp[n-1] != INT_MAX)
                    return dp[n-1];
            }
        }
        return dp[n-1];
    }
};