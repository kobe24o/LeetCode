class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> m;//左端点，对应下标idx
        for(int i = 0; i < intervals.size(); ++i)
        	m[intervals[i][0]] = i;
        vector<int> ans(intervals.size());
        for(int i = 0; i < intervals.size(); ++i)
        {
            auto it = m.lower_bound(intervals[i][1]);
            if(it == m.end())
                ans[i] = -1;
            else
                ans[i] = it->second;
        }
        return ans;
    }
};