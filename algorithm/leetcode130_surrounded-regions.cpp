class Solution {
	int m, n;
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        	return;
        m = board.size(), n = board[0].size();
        int i, j;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if((i==0 || i==m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
        			BFS(board,i,j);
        	}
        }
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if(board[i][j] == '-')
        			board[i][j] = 'O';
        	}
        }
    }

    void BFS(vector<vector<char>>& board, int i, int j)
    {
    	queue<pair<int,int>> q;
    	vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    	q.push({i,j});
    	pair<int,int> tp;
    	board[i][j] = '-';
    	int k, x, y;
    	while(!q.empty())
    	{
    		tp = q.front();
    		q.pop();
    		for(k = 0; k < 4; ++k)
    		{
    			x = dir[k][0]+tp.first;
    			y = dir[k][1]+tp.second;
    			if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O')
    			{
    				q.push({x,y});
    				board[x][y] = '-';
    			}
    		}
    	}
    }
};

class Solution {
	int m, n;
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        	return;
        m = board.size(), n = board[0].size();
        int i, j;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if((i==0 || i==m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
        			DFS(board,i,j,dir);
        	}
        }
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if(board[i][j] == '-')
        			board[i][j] = 'O';
        	}
        }
    }

    void DFS(vector<vector<char>>& board, int i, int j, vector<vector<int>> &dir)
    {
    	board[i][j] = '-';
    	int x, y;
		for(int k = 0; k < 4; ++k)
		{
			x = dir[k][0]+i;
			y = dir[k][1]+j;
			if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O')
				DFS(board,x,y,dir);
		}
    }
};