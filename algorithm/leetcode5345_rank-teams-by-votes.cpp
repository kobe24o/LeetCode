vector<vector<int>> c;
bool cmp(char& a, char& b)
{
    for(int j = 0; j < 26; j++)
    {
        if(c[a-'A'][j] == c[b-'A'][j])
            continue;
        return c[a-'A'][j] > c[b-'A'][j];
    }
    return a < b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int i, j;
        c.clear();//全局变量记得清空，leetcode每次调用不会清空
        vector<int> t(26,0);
        for(i = 0; i < 26; ++i)
            c.push_back(t);
        for(i = 0; i < votes.size(); i++)
        {
            for(j = 0; j < votes[i].size(); j++)
                c[votes[i][j]-'A'][j]++;
        }
        sort(votes[0].begin(), votes[0].end(), cmp);
        return votes[0];
    }
};

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int i, j;
        vector<vector<int>> c(26,vector<int>(26,0));
        for(i = 0; i < votes.size(); i++)
        {
            for(j = 0; j < votes[i].size(); j++)
                c[votes[i][j]-'A'][j]++;
        }
        sort(votes[0].begin(), votes[0].end(), [&](auto a, auto b){
        	for(int j = 0; j < 26; j++)
		    {
		        if(c[a-'A'][j] == c[b-'A'][j])
		            continue;
		        return c[a-'A'][j] > c[b-'A'][j];
		    }
		    return a < b;
        });
        return votes[0];
    }
};