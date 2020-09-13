class Solution {
public:
    bool isTransformable(string s, string t) {
    	int n = s.size();
    	vector<queue<int>> pos(10);
    	for(int i = 0; i < n; ++i) 
    		pos[s[i]-'0'].push(i);
    	for(int i = 0; i < n; ++i)
    	{
    		if(pos[t[i]-'0'].empty())
    			return false;//字符内容对不上
    		for(int d = 0; d < t[i]-'0'; ++d)
    		{
    			if(!pos[d].empty() && pos[d].front() < pos[t[i]-'0'].front())
    				//前面有数字比我小的，升序不可能做到
    				return false;
    		}
            pos[t[i]-'0'].pop();
    	}
    	return true;
    }
};