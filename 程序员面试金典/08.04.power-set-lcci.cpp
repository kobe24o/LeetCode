class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ans;
    	ans.push_back({});
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		for(auto& v : ans)
    		{
    			vector<int> sub = v;
    			sub.push_back(nums[i]);
    			ans.push_back(sub);
    		}
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i, j, k = pow(2,nums.size());
        for(i = 0; i < k; ++i)
        {
            vector<int> sub;
            for(j = 0; j < nums.size(); ++j)
            {
                if(i & (1<<j))
                    sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};