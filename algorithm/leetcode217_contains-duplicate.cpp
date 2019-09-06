class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(s.find(nums[i]) != s.end())
        		return true;
        	else
        		s.insert(nums[i]);
        }
        return false;
    }
};