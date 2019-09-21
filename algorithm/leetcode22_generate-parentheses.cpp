class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> stk;
        vector<string> ans;
        string str;
        int k = 2*n;
        bt(stk,k,0,str,ans);
        return ans;
    }
    void bt(stack<char> stk, int &k, int i, string str, vector<string> &ans)
    {
    	if(i == k)
    	{
    		if(stk.empty())
    			ans.push_back(str);
    		return;
    	}
    	stk.push('(');
    	bt(stk,k,i+1,str+"(",ans);
    	stk.pop();
    	if(!stk.empty())
    	{
    		stk.pop();
    		bt(stk,k,i+1,str+")",ans);
    	}
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        int k = 2*n;
        bt(0,0,k,0,str,ans);
        return ans;
    }
    void bt(int L, int R, int &k, int i, string str, vector<string> &ans)
    {
    	if(L < R)
    		return;
    	if(i == k)
    	{
    		if(L == R)
    			ans.push_back(str);
    		return;
    	}
    	bt(L+1,R,k,i+1,str+"(",ans);
    	bt(L,R+1,k,i+1,str+")",ans);
    }
};