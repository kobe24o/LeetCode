class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int> m;//分数--下标
        int i, k = 4, n = nums.size();
        for(i = 0; i < nums.size(); ++i)
        	m[nums[i]] = i;
        //map是有序的，默认升序
        map<int,int>::reverse_iterator rit = m.rbegin();
        vector<string> ans(nums.size());
        vector<string> reward = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(i = 0; i < min(3,n); ++i,++rit)
        	ans[(*rit).second] = reward[i];
        for( ; rit != m.rend(); ++rit)
        	ans[(*rit).second] = to_string(k++);
        return ans;
    }
};