class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        bt(nums, sub, ans, 0);
        return ans;
    }

    void bt(vector<int>& nums, vector<int> sub, vector<vector<int>> & ans, int i)
    {
    	if(i == nums.size())
		{
			ans.push_back(sub);
			return;
		}
    	bt(nums, sub, ans, i+1);//不加入nums[i]
    	sub.push_back(nums[i]);
    	bt(nums, sub, ans, i+1);//加入nums[i]
    }
};