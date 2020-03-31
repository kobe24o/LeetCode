class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        string origin;
        for(auto& s : strs)
        {
        	origin = s;
        	sort(s.begin(), s.end());
        	m[s].push_back(origin);
        }
        for(auto& mi : m)
        	ans.push_back(mi.second);
        return ans;
    }
};