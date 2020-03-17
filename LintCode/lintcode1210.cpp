class Solution {
    set<vector<int>> s;
    vector<int> v;
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        dfs(nums,0);
        return vector<vector<int>>(s.begin(),s.end());
    }

    void dfs(vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
        {
            if(v.size() >= 2)
                s.insert(v);
            return;
        }
        for(int i = idx; i < nums.size(); ++i)
        {
            dfs(nums,i+1);
            if(v.empty() || v.back() <= nums[i])
            {
                v.push_back(nums[i]);
                dfs(nums,i+1);
                v.pop_back();
            }
        }
    }
};