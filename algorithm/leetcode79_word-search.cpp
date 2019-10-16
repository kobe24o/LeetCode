#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int i, j;
        for(i = 0; i < board.size(); i++)
        	for(j = 0; j < board[0].size(); ++j)
        		dfs(board,i,j,ans,word,0);
        return ans;
    }

    void dfs(vector<vector<char>> &b, int x, int y, bool &ans, string &word, int idx)
    {
    	if(ans == true)
    		return;
    	if(x < 0 || x == b.size() || y < 0 || y == b[0].size() || b[x][y] == '#' || b[x][y] != word[idx]) 
    		return;
    	if(idx == word.size()-1)
    	{
    		if(word[idx] == b[x][y])
    			ans = true;
    		return;
    	}
    	char ch = b[x][y];
    	b[x][y] = '#';//标记走过
    	dfs(b,x+1,y,ans,word,idx+1);
    	dfs(b,x-1,y,ans,word,idx+1);
    	dfs(b,x,y+1,ans,word,idx+1);
    	dfs(b,x,y-1,ans,word,idx+1);
    	b[x][y] = ch;	//恢复现场
    }
};

int main()
{
	vector<vector<char>> b = {{'a','b'},{'c','d'}};
	string w = "abcd";
	Solution s;
	s.exist(b,w);
}