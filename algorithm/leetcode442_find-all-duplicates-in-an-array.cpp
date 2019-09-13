class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 1; i < nums.size(); ++i)
        {
        	if(nums[i] == nums[i-1])
        		ans.push_back(nums[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int temp;
        for(int i = 0; i < nums.size(); ++i)
        {
        	nums[i] > 0 ? temp = nums[i]-1 : temp = -nums[i]-1;
        	//temp 为正数下标, -1防止越界
        	if(nums[temp] > 0)
        		nums[temp] = -nums[temp];
        	else
        		ans.push_back(temp+1);
        }
        return ans;
    }
};