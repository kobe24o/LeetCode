class Solution {
	unordered_map<string,bool> m;
public:
    bool canWin(string s) {
        if(s.size() <= 1) return false;
    	if(m.count(s)) return m[s];
    	string t;
    	for(int i = 0; i < s.size()-1; ++i)
    	{
    		if(s[i]=='+' && s[i+1]=='+')
    		{
    			t = s;
    			t[i]=t[i+1]='-';
    			if(!canWin(t))
    			{
    				m[s] = true;
                    return true;
    			}
    		}
    	}
        m[s] = false;
    	return false;
    }
};