class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');//处理边界方便
        int i, n = s.size();
        string ans;
        stack<string> stk;
        for(i = 0; i < n; ++i)
        {
        	if(s[i] != ' ')
        		ans += s[i];
        	else// (s[i]==' ')
        	{
        		if(ans.size())
        		{
        			stk.push(ans);
        			ans.clear();
        		}
        	}
        }
        while(!stk.empty())
        {
        	ans += stk.top()+" ";
        	stk.pop();
        }
        ans.pop_back();
        return ans;
    }
};