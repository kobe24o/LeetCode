class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	if(board.empty())
    		return;
        vector<vector<int>> cp(board);
        int nearby[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        					{1, 0},  {1, 1},    {0, 1}, {-1, 1}};
		int m = board.size(), n = board[0].size(), i, j, k, x, y, live;
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				live = 0;
				for(k = 0; k < 8; ++k)
				{
					x = i+nearby[k][0];
					y = j+nearby[k][1];
					if(x>=0 && x<m && y>=0 && y<n && cp[x][y])
						live++;
				}
				if(cp[i][j])
				{
					if(live < 2 || live > 3)
						board[i][j] = 0;
				}
				else
				{
					if(live == 3)
						board[i][j] = 1;
				}
			}
		}
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	if(board.empty())
    		return;
        int nearby[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        					{1, 0},  {1, 1},    {0, 1}, {-1, 1}};
		int m = board.size(), n = board[0].size(), i, j, k, x, y, live;
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				live = 0;
				for(k = 0; k < 8; ++k)
				{
					x = i+nearby[k][0];
					y = j+nearby[k][1];
					if(x>=0 && x<m && y>=0 && y<n && (board[x][y]==1 || board[x][y]==2))
						live++;
				}
				if(board[i][j])
				{
					if(live < 2 || live > 3)
						board[i][j] = 2;
				}
				else
				{
					if(live == 3)
						board[i][j] = 3;
				}
			}
		}
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(board[i][j] == 2)
					board[i][j] = 0;
				else if(board[i][j] == 3)
					board[i][j] = 1;
			}
		}
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size(), i, j, k, x, y, live;
		int nearby[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        					{1, 0},  {1, 1},    {0, 1}, {-1, 1}};        
		for (i = 0; i < m; ++i) 
		{
            for (j = 0; j < n; ++j) 
            {
                for (k = 0; k < 8; ++k) 
                {
                    x = i + nearby[k][0];
                    y = j + nearby[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n)
                        board[i][j] += (board[x][y] & 1) << 1;
                }
            }
        }
        for (i = 0; i < m; ++i) 
        {
            for (j = 0; j < n; ++j) 
            {
                live = board[i][j] >> 1;
                if (live < 2 || live > 3) 
                    board[i][j] = 0;
                else if (live == 3)
                    board[i][j] = 1;
                else
                    board[i][j] &= 1;
            }
        }
    }
};