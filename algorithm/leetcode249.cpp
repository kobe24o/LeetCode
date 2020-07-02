class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
    	unordered_map<string,vector<string>> m;
    	string key;
    	for(string& s : strings)
    	{
            key = s;
            int dis = s[0]-'a';
            for(int i = 0; i < key.size(); ++i)
                key[i] = (key[i]-dis+26)%26;
            m[key].push_back(s);
    	}
    	vector<vector<string>> ans(m.size());
    	int i = 0;
    	for(auto it = m.begin(); it != m.end(); ++it)
    		ans[i++] = it->second;
    	return ans;
    }
};