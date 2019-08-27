class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> row;
        vector<vector<int>> ans;
        bool occurred[nums.size()];
        memset(occurred, 0, sizeof(bool)*nums.size());
        sort(nums.begin(), nums.end());
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
                if(i >= 1 && nums[i-1] == nums[i] && !occurred[i-1])
                    continue;//搜索剪枝
                occurred[i] = true;
                row.push_back(nums[i]);
                bt(nums,count+1,occurred,row,ans);
                row.pop_back();
                occurred[i] = false;
            }
        }
    }
};