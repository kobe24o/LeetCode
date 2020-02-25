class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
    	if(s1.size() != s2.size())
    		return false;
    	unordered_map<char,int> m;
    	for(int i = 0; i < s1.size(); ++i)
    	{
    		m[s1[i]]++;
    		m[s2[i]]--;
    	}
    	for(auto& mi : m)
    		if(mi.second != 0)
    			return false;
		return true;
    }
};