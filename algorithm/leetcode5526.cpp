class Solution {
    int max_satisfied = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n, 0);
        dfs(requests, count, 0, 0);
        return max_satisfied;
    }
    void dfs(vector<vector<int>>& requests, vector<int>& count, int idx, int satisfied)
    {
        if(satisfied+requests.size()-idx <= max_satisfied)
            return;//剩余的假如都可以满足，都不可能超过最大的
        if(idx == requests.size())
        {
            for(int i = 0; i < count.size(); i++)
            {
                if(count[i] != 0)
                    return;
            }
            max_satisfied = max(max_satisfied, satisfied);
            return;
        }
        dfs(requests, count, idx+1, satisfied);//当前不选

        int from = requests[idx][0], to = requests[idx][1];
        count[from]--;
        count[to]++;
        dfs(requests, count, idx+1, satisfied+1);
        count[from]++;
        count[to]--;
    }
};