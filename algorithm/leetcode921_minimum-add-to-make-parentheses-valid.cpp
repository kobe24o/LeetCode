class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        for(int i = 0; i < S.size(); ++i)
        {
        	if(stk.empty())
        		stk.push(S[i]);
        	else
        	{
        		if(stk.top()=='(' && S[i]==')')
        			stk.pop();
        		else
        			stk.push(S[i]);
        	}
        }
        return stk.size();
    }
};

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int right = 0;
        for(char &c:S)
        {
            if(c=='(') 
                left++;
            else
            {
                if(left>0) 
                    left--;
                else 
                    right++;
            }   
        }
        return left+right;
    }
};