class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int> row;
        vector<vector<int>> ans;
        bt(nums, ans);
    }
    void bt(vector<int>& nums, vector<vector<int>>& ans)
    {
    	
    }
};