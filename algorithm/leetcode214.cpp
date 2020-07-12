class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return "";
        if(ispalindrom(s))
            return s;
    	int n = s.size(), idx, maxlen = 0;
        string t;
        bool odd;
    	for(int i = 0; i <= n/2; ++i)
    	{
            t = s.substr(i, i+1);
            reverse(t.begin(), t.end());
    		if(s.substr(0,i+1) == t )
    		{
    			idx = i;
                odd = true;
    		}
            t = s.substr(i+1, i+1);
            reverse(t.begin(), t.end());
            if(s.substr(0,i+1) == t )
    		{
    			idx = i+1;
                odd = false;
    		}
    	}
        if(odd)
    	    t = s.substr(2*idx+1);
        else
            t = s.substr(2*idx);
    	reverse(t.begin(), t.end());
    	return t+s;
    }
    bool ispalindrom(string &s)
    {
        int l = 0, r = s.size()-1;
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
};