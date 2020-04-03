class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int i = 0, j = nums.size()-1;
    	vector<vector<int>> ans;
    	while(i < j)
    	{
    		if(nums[i]+nums[j]== target)
    			ans.push_back({nums[i++],nums[j--]});
    		else if(nums[i]+nums[j] < target)
    			i++;
    		else
    			j--;
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
    	unordered_map<int,int> m;
    	vector<vector<int>> ans;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(m[target-nums[i]] > 0)
    		{
    			ans.push_back({nums[i],target-nums[i]});
    			m[target-nums[i]]--;
    		}
    		else
    			m[nums[i]]++;
    	}
    	return ans;
    }
};