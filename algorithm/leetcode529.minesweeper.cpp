class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    	if(board[click[0][click[1]]] == 'M')
    	{
    		board[click[0][click[1]]] = 'X';
    		return board;
    	}
    	vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    	int m = board.size(), n = board[0].size();
    	int i, j, x, y, k, count;
    	queue<vector<int>> q;
    	q.push(click);
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
    			if(x>=0 && x<m && y>=0 && y<n)
    			{
    				if(board[x][y]=='M')
    					count++;
    				else if(board[x][y]=='E')
    				{
    					q.push({x,y});
    				}
    			}
    		}
    		board[i][j] = count==0 ? 'B' : char('0'+count);
    	}
    	return board;
    }
};