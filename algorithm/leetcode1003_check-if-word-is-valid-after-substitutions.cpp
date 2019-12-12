class Solution {
public:
    bool isValid(string S) {
        if(S.size()%3 != 0 || S[0] != 'a')
        	return false;
        stack<char> stk;
        for(int i = 0; i < S.size(); ++i)
        {
        	if(S[i] == 'c')
        	{
        		if(stk.empty() || (!stk.empty() && stk.top() != 'b'))
        			return false;
        		else
        		{
        			stk.pop();
        			if(stk.empty() || (!stk.empty() && stk.top() != 'a'))
        				return false;
        			else
        				stk.pop();
        		}
        	}
        	else
        		stk.push(S[i]);
        }
        return stk.empty();
    }
};