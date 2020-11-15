class Solution {
    bool ans = false;
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> m;
        for(auto n : nums)
            m[n]++;
        vector<int> val(m.size(), 0);
        int i = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
            val[i++] = it->second;
        sort(val.rbegin(), val.rend());
        sort(quantity.rbegin(), quantity.rend());
        dfs(val, quantity, 0);
        return ans;
    }
    void dfs(vector<int>& val, vector<int>& quantity, int i)
    {
        if(ans)
            return;
        if(i == quantity.size())
        {
            ans = true;
            return;
        }
        for(int j = 0; j < val.size(); ++j)
        {
            if(val[j]-quantity[i] >= 0)
            {
                val[j] -= quantity[i];
                dfs(val, quantity, i+1);
                val[j] += quantity[i];
            }
        }
    }
};