class Solution {
	bool found = false;
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        m = board.size(), n = board[0].size();
        for(i = 0; i < board.size(); ++i)
        {
        	for(j = 0; j < board[0].size(); ++j)
        		if(!found)
        			dfs(board,i,j,word,0);
        		else
        			return found;
        }
        return found;
  	}

    void dfs(vector<vector<char>>& board, int i, int j, string& word, int w)
    {
    	if(found || (w<word.size() && board[i][j] != word[w]))
    		return;
    	if(w==word.size()-1)
    	{
    		found = true;
    		return;
    	}
    	int x, y;
    	char ch;
    	for(int k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x >=0 && x<m && y>=0 && y<n)
    		{
    			ch = board[i][j];
    			board[i][j] = '*';
    			dfs(board,x,y,word,w+1);
    			board[i][j] = ch;
    		}
    	}
    	
    }
};