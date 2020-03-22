class Solution {
public:
    string longestPrefix(string s) {
    	string ans;
        for(int i = 1; i < s.size(); ++i)
        {
        	string::view sub = s.substr(0,i);
        	if(s.find(sub) != string::npos)
        	{
        		ans = sub;
        	}
        }
        return ans;
    }
};


class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.size()+1);
        calNext(next, s);
        return s.substr(0,next.back());
    }

    void calNext(vector<int> &next, string& s)
    {	//字符串中前缀与后缀的最长匹配长度
    	//next[j]=k , 在j之前的子串的最长匹配长度为k
    	int j = 0, k = -1;
    	next[0] = -1;
    	while(j < s.size())
    	{
    		if(k == -1 || s[j] == s[k])
			// 有[0, ..., k-1]与[j-k, ..., j-1] 匹配, 同时 s[j] == s[k]
    			next[++j] = ++k;
    			//匹配长度增加 1, 查看下一个匹配位置
    		else
    			k = next[k];
    			//不匹配, 当前查看的前缀太长, k跳回到上一个可能的匹配位置
    	}
    }
};