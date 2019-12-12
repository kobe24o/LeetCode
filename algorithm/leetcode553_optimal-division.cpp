class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        int i = 0;
        if(nums.size() <= 2)
        {
        	while(i < nums.size())
        	{
        		ans += to_string(nums[i++])+"/";
        	}
        	ans.pop_back();
        	return ans;
        }
        ans += to_string(nums[0])+"/(";
        for(i = 1; i < nums.size(); ++i)
        {
        	ans += to_string(nums[i])+"/";
        }
        ans.pop_back();
        ans.push_back(')');
        return ans;
    }
};