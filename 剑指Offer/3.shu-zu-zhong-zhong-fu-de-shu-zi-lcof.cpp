class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& n : nums)
        {
        	if(!s.count(n))
        		s.insert(n);
        	else
        		return n;
        }
        return -1;
    }
};