class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        multimap<int,int> m;
        for(int i = 0; i < groupSizes.size(); ++i)
        	m.emplace(groupSizes[i],i);
        vector<vector<int>> ans(1);
        for(auto& kv : m)
        {
        	if(ans.back().size() < kv.first)
        		ans.back().push_back(kv.second);
        	if(ans.back().size() == kv.first)
        		ans.push_back({});
        }
        if(ans.back().size() == 0)
        	ans.pop_back();
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> temp(500);
        vector<vector<int>> ans;
        for(int i = 0; i < groupSizes.size(); ++i)
        {
            temp[groupSizes[i]].push_back(i);
            if(temp[groupSizes[i]].size() == groupSizes[i])
            {
                ans.push_back(temp[groupSizes[i]]);
                temp[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};