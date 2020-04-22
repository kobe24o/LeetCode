class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	if(nums.size() < 3)
    		return false;
    	stack<int> s;//单调递减栈
    	int Ak = INT_MIN;//第二大的数
    	for(int i = nums.size()-1; i >= 0; --i)
    	{
    		if(Ak > nums[i])
    			return true;
    		while(!s.empty() && nums[i] > s.top())
    		{
    			Ak = s.top();
    			s.pop();
    		}
    		s.push(nums[i]);
    	}
    	return false;
    }
};