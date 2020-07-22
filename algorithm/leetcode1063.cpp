class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
        	while(!s.empty() && nums[i] >= nums[s.top()])
        	{
        		s.pop();
        	}
        	count += i-s.top();
        	s.push(i);
        }
        return count;
    }
};