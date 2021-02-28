class Solution {
    int ans = INT_MAX;
    int diff = INT_MAX;
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size();
        for(int i = 0; i < n; i++)
        {
            dfs(toppingCosts, 0, baseCosts[i], target);
        }
        return ans;
    }
    void dfs(vector<int>& toppingCosts, int idx, int val, int target)
    {
        if(abs(val-target) < diff || (abs(val-target)==diff && val < ans))
        {
            ans = val;
            diff = abs(val-target);
        }
        if(idx == toppingCosts.size())
            return;
        dfs(toppingCosts, idx+1, val, target);//不拿
        dfs(toppingCosts, idx+1, val+toppingCosts[idx], target);//拿一份
        dfs(toppingCosts, idx+1, val+2*toppingCosts[idx], target);//拿2份
    }
};