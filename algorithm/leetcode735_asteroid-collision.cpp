class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> stk;
        for(int i = 0; i < asteroids.size(); ++i)
        {
        	if(stk.empty())
        	{
        		stk.push(asteroids[i]);
        		continue;
        	}
        	if(!(stk.top()>0 && asteroids[i]<0))
        		stk.push(asteroids[i]);
        	else
        	{
        		if(stk.top() == abs(asteroids[i]))
        			stk.pop();
        		else if(stk.top() < abs(asteroids[i]))
        		{
        			stk.pop();
        			i--;//一会还要i++，还没撞掉，再来一遍
        		}
        	}
        }

        while(!stk.empty())
        {
        	ans.insert(ans.begin(), stk.top());
        	stk.pop();
        }
        return ans;
    }
};