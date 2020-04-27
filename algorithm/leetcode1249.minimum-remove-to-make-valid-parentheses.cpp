class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> stk;
        set<int> del;//要删除的idx存储取来
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		stk.push(i);
        	else if(s[i] == ')')
        	{
        		if(!stk.empty())
        			stk.pop();
        		else
        			del.insert(i);//栈为空，碰到 ),要删除
        	}
        }
        while(!stk.empty())//结束后栈不为空，也要删除
        {
        	del.insert(stk.top());
        	stk.pop();
        }
        auto it = del.begin();//遍历要删除的
        for(int i = 0; i < s.size(); ++i)
        {
        	if(it != del.end() && i == *it)
        	{
                it++;
                continue;//跳过要删除的
            }
        	ans += s[i];
        }
        return ans;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> stk;
        unordered_set<int> del;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		stk.push(i);
        	else if(s[i] == ')')
        	{
        		if(!stk.empty())
        			stk.pop();
        		else
        			del.insert(i);
        	}
        }
        while(!stk.empty())
        {
        	del.insert(stk.top());
        	stk.pop();
        }
        for(int i = 0; i < s.size(); ++i)
        {
        	if(del.count(i))
                continue;
        	ans += s[i];
        }
        return ans;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        deque<int> q;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		q.push_back(i);
        	else if(s[i] == ')')
        	{
        		if(!q.empty() && s[q.back()]=='(')
        			q.pop_back();
        		else
        			q.push_back(i);;
        	}
        }
        for(int i = 0, j = 0; i < s.size(); ++i)
        {
        	if(j < q.size() && i == q[j])
            {
                j++;
                continue;
            }
        	ans += s[i];
        }
        return ans;
    }
};