class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string ans;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] != ' ' && i != s.size()-1)
        	{
        		stk.push(s[i]);
        	}
        	else if(s[i] != ' ' && i == s.size()-1)
        	{
        		ans.push_back(s[i]);
        		while(!stk.empty())
        		{
        			ans.push_back(stk.top());
        			stk.pop();
        		}
        	}
        	else
        	{
        		while(!stk.empty())
        		{
        			ans.push_back(stk.top());
        			stk.pop();
        		}
        		ans.push_back(s[i]);
        	}
        }
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans, substr;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] != ' ' && i != s.size()-1)
        	{
        		substr.push_back(s[i]);
        	}
        	else if(s[i] != ' ' && i == s.size()-1)
        	{
        		substr.push_back(s[i]);
                reverse(substr.begin(),substr.end());
        		ans += substr;
        	}
        	else
        	{
        		reverse(substr.begin(),substr.end());
        		ans += substr;
        		substr = "";
        		ans.push_back(s[i]);
        	}
        }
        return ans;
    }
};