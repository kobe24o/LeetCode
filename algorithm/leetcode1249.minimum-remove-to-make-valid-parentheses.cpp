class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> s;
        unordered_set<int> del;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		s.push(i);
        	else if(s[i] == ')')
        	{
        		if(!s.empty())
        			s.pop_back();
        		else
        			del.insert(i);
        	}
        }
        while(!s.empty())
        {
        	del.insert(s.top());
        	s.pop();
        }
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s.count(i))
        		continue;
        	ans += s[i];
        }
        return ans;
    }
};