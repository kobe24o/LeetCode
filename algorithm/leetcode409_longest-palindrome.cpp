class Solution {
public:
    int longestPalindrome(string s) {
        int count[52] = {0};
        for(int i = 0; i < s.size(); i++)
        {
        	if(islower(s[i]))
        		count[s[i]-'a']++;
        	else
        		count[s[i]-'A'+26]++;
        }
        bool single = false;
        int len = 0;
        for(int i = 0; i < 52; ++i)
        {
        	if(count[i]%2 == 0)
        		len += count[i];
        	else
        	{
        		len += count[i]-1;
        		single = true;
        	}
        }
        if(single)
        	return len+1;
        return len;
    }
};