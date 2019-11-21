class Solution {
	vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
public:
	int robotSim(vector<int>& cmd, vector<vector<int>>& ob) {
		int d = 0, x = 0, y = 0, maxDis = 0, i;
		set<pair<int,int>> s;
		for(vector<int> o:ob)
			s.insert(make_pair(o[0],o[1]));

		for(int c : cmd) 
		{
			if(c == -2)//左转
				d = (d-1+4)%4;
			else if(c == -1)//右转
				d = (d+1)%4;
			else //模拟
			{
				for(i=0; i<c; i++) 
				{
					x += dir[d][0];
					y += dir[d][1];
					if(s.find(make_pair(x,y)) != s.end()) 
					{	//是障碍物
						x -= dir[d][0];
						y -= dir[d][1];
						break;//退回一格，停止
					}
				}
				maxDis = max(maxDis, x*x+y*y);
			}
		}
		return maxDis;
    }
};