class Solution {
public:
    string minWindow(string s, string t) {
    	if(s == "" || t == "" || s.size() < t.size())
    		return "";
        unordered_map<char,int> m;
        for(char c : t)
        	m[c]++;
        string ans;
        int left = 0, right = 0, len = 0, minLen = INT_MAX;
        for( ; right < s.size(); ++right)
        {
    		m[s[right]]--;//希望t中的字符计数为0
    		if(m[s[right]]>=0)//不存在t中的字符计数是负的
    			++len;
    		while(len == t.size())//窗口包含所有的t的字符了
    		{
    			if(right-left+1 < minLen)//更新最小窗口长度
    			{
    				minLen = right-left+1;
    				ans = s.substr(left,minLen);
    			}
    			m[s[left]]++;//缩短left，计数+1(非t字符趋近0，t中字符变为正)
				if(m[s[left]] > 0)//t中的字符
					--len;//窗口包含t的字符数-1
				left++;//缩短左窗口
    		}
        }
        return ans;
    }
};