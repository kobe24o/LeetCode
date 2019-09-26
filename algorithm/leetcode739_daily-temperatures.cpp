class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(),0);
        stack<int> stk;
        for(int i = 0; i < T.size(); ++i)
        {
        	while(!stk.empty() && T[stk.top()] < T[i])
        	{
        		ans[i] = i-stk.top();
        		stk.pop();
        	}
        	stk.push(i);
        }
        return ans;
    }
};