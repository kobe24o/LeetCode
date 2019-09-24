class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms, mt;
        for(int i = 0; i < s.size(); ++i)
        {
        	auto it = ms.find(s[i]);
        	if(it == ms.end())
        	{
        		ms[s[i]] = t[i];
        		if(mt.find(t[i]) == mt.end())
					mt[t[i]] = s[i];
				else
				{
					if(mt.find(t[i])->second != s[i])
						return false;
				}
        	}
        	else
        	{
        		if(m[s[i]] != t[i])
        			return false;
        	}
        }
        return true;
    }
};