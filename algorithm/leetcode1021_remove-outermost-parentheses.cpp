class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> stk;
        string innerStr("");
        for(int i = 1; i < S.size(); ++i)
        {//跳过i=0的外层括号(
        	if(S[i] == ')')
        	{
        		if(stk.empty())//不能匹配，说明是外层
        		{
	        		i += 1;//跳过外层
	        		continue;
        		}
        		else
        		{
        			innerStr.push_back(S[i]);
        			stk.pop();
        		}
        	}
        	else// S[i] == '('
        	{
        		stk.push(S[i]);
        		innerStr.push_back(S[i]);
        	}
        }
        return innerStr;
    }
};