class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int> row;
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        bt(nums, 0, m, row, ans);
        return ans;
    }
    void bt(vector<int>& nums, int count, unordered_map<int, int> m, vector<int> row, vector<vector<int>>& ans)
    {
    	if(count == nums.size())
        {
            ans.push_back(row);   
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m.find(i) == m.end())
            {
                m[i] = 1;
                row.push_back(nums[i]);
                bt(nums,count+1,m,row,ans);
                row.pop_back();
                m.erase(i);
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int> row;
        vector<vector<int>> ans;
        bool occurred[nums.size()];
        memset(occurred, 0, sizeof(bool)*nums.size());
        bt(nums, 0, occurred, row, ans);
        return ans;
    }
    void bt(vector<int>& nums, int count, bool *occurred, vector<int> row, vector<vector<int>>& ans)
    {
        if(count == nums.size())
        {
            ans.push_back(row);   
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(occurred[i] == false)
            {
                occurred[i] = true;
                row.push_back(nums[i]);
                bt(nums,count+1,occurred,row,ans);
                row.pop_back();
                occurred[i] = false;
            }
        }
    }
};