class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n, i, j, k, step = 0, size, x, y;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
    	m = board.size(), n = board[0].size();
    	string ans = "123450", state;
    	int x0, y0, xi, yi;
    	pair<int,int> xy0;//0的坐标
    	queue<string> q;
    	unordered_set<string> visited;//访问标记集合
    	state = boardToString(board);//初始状态
    	if(state == ans)
    		return step;
    	q.push(state);
    	visited.insert(state);
    	while(!q.empty())
    	{
    		step++;
    		size = q.size();
    		while(size--)
    		{
    			xy0 = stringToBoard(q.front(), board);//还原地图，并得到0的坐标
    			q.pop();
    			x0 = xy0.first;
    			y0 = xy0.second;
    			for(k = 0; k < 4; ++k)
    			{	//0可以4个方向交换
    				xi = x0+dir[k][0];
    				yi = y0+dir[k][1];
    				if(xi>=0 && xi<m && yi>=0 && yi<n)
    				{
    					swap(board[xi][yi], board[x0][y0]);//交换
    					state = boardToString(board);//新的状态
                        if(state == ans)
                            return step;
    					if(!visited.count(state))//没有出现过该地图
    					{
    						visited.insert(state);
    						q.push(state);
    					}
    					swap(board[xi][yi], board[x0][y0]);//还原现场
    				}

    			}
    		}
    	}
    	return -1;
    }

    string boardToString(vector<vector<int>>& board) 
    {	//地图转成字符串
    	string s;
    	for (i = 0; i < m; i++)
    		for(j = 0; j < n; j++)
    			s.push_back(board[i][j]+'0');
		return s;
    }

    pair<int,int> stringToBoard(string &s, vector<vector<int>>& board)
    {	//字符串还原成地图，并return 0的坐标，方便下次挪动
    	for (i = m-1; i >= 0; i--)
    		for(j = n-1; j >= 0; j--)
    		{
    			board[i][j] = s.back()-'0';
    			s.pop_back();
    			if(board[i][j] == 0)
    				x = i, y = j;
    		}
    	return make_pair(x, y);
    }
};