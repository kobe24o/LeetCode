class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i, count = 0;
        stack<pair<char,int>> stk;
        char prev = '*';
        for(i = 0; i < s.size(); ++i)
        {
        	if(prev != s[i])
        	{
        		count = 1;
        		stk.push(make_pair(s[i],count));
        		prev = s[i];
        	}
        	else//prev == s[i]
        	{
        		count = stk.top().second + 1;
        		stk.push(make_pair(s[i],count));
        		prev = s[i];
        		if(count == k)
        		{
        			while(count--)
        			{
        				stk.pop();
        			}
        			if(!stk.empty())
        				prev = stk.top().first;
        			else
        				prev = '*';
        		}
        	}
        }
        string ans;
        while(!stk.empty())
        {
        	ans += stk.top().first;
        	stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {//优化版
public:
    string removeDuplicates(string s, int k) {
        int i, count = 0;
        stack<pair<char,int>> stk;
        char prev = '*';
        for(i = 0; i < s.size(); ++i)
        {
            if(prev != s[i])
            {
                count = 1;
                stk.push(make_pair(s[i],count));
                prev = s[i];
            }
            else//prev == s[i]
            {
                stk.top().second++;
                if(stk.top().second == k)
                {
                    stk.pop();
                    if(!stk.empty())
                        prev = stk.top().first;
                    else
                        prev = '*';
                }
            }
        }
        string ans;
        while(!stk.empty())
        {
            count = stk.top().second; 
            while(count--)   
                ans += stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};