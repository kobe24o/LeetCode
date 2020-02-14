class Solution {
public:
    char firstUniqChar(string s) {
    	unordered_map<char,int> m;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(m.count(s[i]))
        		m[s[i]] = -1;//标记为-1表示出现多次
        	else
        		m[s[i]] = i;//存储位置
        }
        int idx = INT_MAX;
        char ans = ' ';
        for(auto& mi : m)
        {
        	if(mi.second != -1 && mi.second < idx)
        	{
        		idx = mi.second;
        		ans = mi.first;
        	}
        }
        return ans;
    }
};

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> count(128,-1);
        for(int i = 0; i < s.size(); ++i)
        {
        	if(count[s[i]] == -1)//-1表示没有出现
        		count[s[i]] = i;//存储位置
        	else//出现过
        		count[s[i]] = -2;//表示重复
        }
        char ans = ' ';
        int idx = INT_MAX;
        for(int i = 0; i < 128; ++i)
        	if(count[i] != -1 && count[i] != -2 && count[i] < idx)
        	{
        		ans = i;
        		idx = count[i];
        	}
        return ans;
    }
};