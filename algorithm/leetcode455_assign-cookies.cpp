class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, i, j = 0;
        for(i = 0; i < g.size(); ++i)
        {
        	while(j < s.size() && s[j] < g[i])//饼干不够大
        		j++;
        	if(j < s.size())
        	{
        		++count;
        		++j;
        	}
        	else//饼干发完了
        		break;
        }
        return count;
    }
};