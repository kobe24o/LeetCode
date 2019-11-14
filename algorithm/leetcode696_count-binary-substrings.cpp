class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, ans = 0;
        for(int i = 1; i < s.size(); ++i)
        {
        	if(s[i-1] == s[i])
        		cur++;
        	else//不等了
        	{
        		prev = cur;
        		cur = 1;
        	}
        	if(prev >= cur)
        		ans++;
        }
        return ans;
    }
};