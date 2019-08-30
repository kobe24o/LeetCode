class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> ans;
        bt(nums,sub,ans,0);
       	return ans;
    }
    void bt(vector<int>& nums,vector<int> sub, vector<vector<int>> &ans, int i)
    {
    	if(i == nums.size())
    	{
    		ans.push_back(sub);
    		return;
    	}
    	if(i > 0 && nums[i-1] == nums[i])
        {
            sub.push_back(nums[i]);
            return;
        }
    	bt(nums,sub,ans,i+1);
    	sub.push_back(nums[i]);
    	bt(nums,sub,ans,i+1);
    }
};