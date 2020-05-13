class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        int i, count = 1, prev = nums[0];
        string s = to_string(nums[0]);
        vector<string> ans;
        for(i = 1; i < nums.size(); ++i)
        {
        	if(long(nums[i])-prev != 1)//[-2147483648,-2147483647,2147483647]int溢出
        	{
                if(count != 1)
                    s += "->"+to_string(nums[i-1]);
        		ans.push_back(s);
        		s = to_string(nums[i]);
                count = 1;
        	}
        	else
        		count++;
        	prev = nums[i];
        }
        if(count != 1)
            s += "->"+to_string(nums[i-1]);
        ans.push_back(s);
        return ans;
    }
};