class Solution {
public:
    string shortestPalindrome(string s) {
    	int n = s.size(), idx;
    	for(int i = 0; i <= n/2; ++i)
    	{
    		if(s.substr(0,i+1) == s.substr(i, i+1))
    		{
    			idx = i+1;
    		}
    	}
    	string t = s.substr(idx);
    	reverse(t.begin(), t.end());
    	return t+s;
    }
};