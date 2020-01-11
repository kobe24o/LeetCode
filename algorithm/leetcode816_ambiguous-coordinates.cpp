class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1,S.size()-2);
        string a, b;
        int i, j, k, na, nb, n = S.size();
        vector<string> ans;
        for(i = 1; i < n; ++i)
        {
        	a = S.substr(0,i);
        	b = S.substr(i);
        	na = a.size();
        	nb = b.size();
        	for(j = 0; j < na; ++j)
        	{
        		if(j != 0)
        			a.insert(j,1,'.');
        		for(k = 0; k < nb; ++k)
        		{
        			if(k != 0)
        				b.insert(k,1,'.');
        			if(isok(a) && isok(b))
        				ans.push_back("("+a+", "+b+")");
        			if(k != 0)
        				b.erase(k,1);
        		}
        		if(j != 0)
        			a.erase(j,1);
        	}
        }
        return ans;
    }

    bool isok(const string& s)
    {
    	bool hasdot = false;
    	for(auto& ch : s)
    		if(ch == '.')
    			hasdot = true;
		if(hasdot && (s.back()=='0' || (s[0]=='0'&&s[1] != '.')))
			return false;
		else if(!hasdot && s.size()>1 && s[0] == '0')
			return false;
		return true;
    }
};