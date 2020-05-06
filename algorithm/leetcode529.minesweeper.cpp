class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    	if(board[click[0]][click[1]] == 'M')//点击的是地雷，直接标记X，结束
    	{
    		board[click[0]][click[1]] = 'X';
    		return board;
    	}
    	vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    	int m = board.size(), n = board[0].size();
    	int i, j, x, y, k, count;
    	queue<vector<int>> q;
    	q.push(click);
        vector<vector<bool>> visited(m,vector<bool>(n,false));//访问标记
        visited[click[0]][click[1]] = true;
    	while(!q.empty())
    	{
    		i = q.front()[0];
    		j = q.front()[1];
    		q.pop();
    		count = 0;
    		for(k = 0; k < 8; ++k)
    		{
    			x = i + dir[k][0];
    			y = j + dir[k][1];
    			if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='M')
                    count++;//8个方向有几颗地雷
    		}
            if(count == 0)//地雷为0，需要周围的都加入队列，去检查是否继续翻开
            {
                board[i][j] = 'B';//中间标记为B
                for(k = 0; k < 8; ++k)
                {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && board[x][y]=='E')
                    {
                        q.push({x,y});
                        visited[x][y] = true;
                    }
                }
            }
            else
            {	//不为零，标记为数字
    		    board[i][j] = char('0'+count);
            }
    	}
    	return board;
    }
};

class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    int m,n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    	if(board[click[0]][click[1]] == 'M')
    	{
    		board[click[0]][click[1]] = 'X';
    		return board;
    	}
    	m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[click[0]][click[1]] = true;
    	dfs(board,click[0],click[1],visited);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
    {
        int x, y, k, count = 0;
        for(k = 0; k < 8; ++k)
        {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='M')
                count++;//8个方向有几颗地雷
        }
        if(count == 0)//地雷为0，需要周围的都加入队列，去检查是否继续翻开
        {
            board[i][j] = 'B';//中间标记为B
            for(k = 0; k < 8; ++k)
            {
                x = i + dir[k][0];
                y = j + dir[k][1];
                if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && board[x][y]=='E')
                {
                    visited[x][y] = true;
                    dfs(board,x,y,visited);
                }
            }
        }
        else
        {	//不为零，标记为数字
            board[i][j] = char('0'+count);
        }
    }
};