class Solution {
public:
    string alphabetBoardPath(string target) {
        string s = "abcdefghijklmnopqrstuvwxyz";
        map<char,pair<int,int>> m;
        for(int i = 0; i < 26; ++i)
        {
        	m[s[i]] = make_pair(i/5,i%5);
        }
        string ans;
        int x = 0, y = 0;
        for(int i = 0; i < target.size(); ++i)
        {
            while(y > m[target[i]].second)
        	{
        		ans.push_back('L');
        		--y;
        	}
        	while(x < m[target[i]].first)
        	{
        		ans.push_back('D');
        		++x;
        	}
        	while(x > m[target[i]].first)
        	{
        		ans.push_back('U');
        		--x;
        	}
        	while(y < m[target[i]].second)
        	{
        		ans.push_back('R');
        		++y;
        	}
        	ans.push_back('!');
        }
        return ans;
    }
};