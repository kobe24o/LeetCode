class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> s;
        nums.push_back(-1); # 保证最后全部清空栈
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
        	while(!s.empty() && nums[i] < nums[s.top()])
        	{
                count += i-s.top();
        		s.pop();
        	}
        	s.push(i);
        }
        return count;
    }
};