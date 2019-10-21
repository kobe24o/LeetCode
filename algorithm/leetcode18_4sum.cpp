class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
        	return {};
        int i, j, k, l, sum;
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(i = 0; i < nums.size()-3; ++i)
        {
        	for(j = i+1; j < nums.size()-2; ++j)
        	{
        		k = j+1, l = nums.size()-1;
        		while(k < l)
        		{
        			sum = nums[i]+nums[j]+nums[k]+nums[l];
        			if(sum < target)
        				k++;
        			else if(sum > target)
        				l--;
        			else
        			{
        				s.insert({nums[i],nums[j],nums[k],nums[l]});
        				k++,l--;
        			}
        		}
        	}
        }
        for(auto v:s)
        	ans.push_back(v);
        return ans;
    }
};