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