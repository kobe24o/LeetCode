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

class Solution {
	int count[26] = {0};
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        string origin;
        for(auto& s : strs)
        {
        	origin = s;
        	mysort(s);
        	m[s].push_back(origin);
        }
        for(auto& mi : m)
        	ans.push_back(mi.second);
        return ans;
    }
    void mysort(string& s)
    {
    	for(int i = 0; i < s.size(); ++i)
    		count[s[i]-'a']++;
    	s = "";
    	for(int i = 0; i < 26; ++i)
    	{
    		while(count[i])
    		{
                s += i+'a';
                count[i]--;
            }
    	}
    }
};