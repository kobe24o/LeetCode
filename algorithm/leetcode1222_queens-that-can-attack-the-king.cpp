class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int i,j,k;
        set<pair<int,int>> s;
        vector<vector<int>> pos;
        for(i = 0; i < queens.size(); i++)
        	s.insert(make_pair(queens[i][0], queens[i][1]));
        for(k = 0; k < dir.size(); ++k)
        {
        	i = king[0];
        	j = king[1];
        	while(1)
        	{
        		i += dir[k][0];
        		j += dir[k][1];
        		if(!(i>=0 && i<8 && j>=0 && j<8))
        			break;
        		else
        		{
        			if(s.count(make_pair(i,j)))
        			{
        				pos.push_back({i,j});
        				break;
        			}
        		}
        	}
        }
        return pos;
    }
};