struct node
{
	int push, bi, bj, pi, pj;
	node(int n, int a, int b, int c, int d)
	{
		push = n;
		bi = a;
		bj = b;
		pi = c;
		pj = d;
	}
};
struct cmp
{
	bool operator()(node& a, node& b) const
	{
		return a.push > b.push;//推得次数少的优先
	}
};
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
    	int m = grid.size(), n = grid[0].size(), k = 21;
    	int targetx, targety, boxi, boxj, peoplei, peoplej, push = 0, size;
    	for(int i = 0; i < m; i++) 
    	{
    		for(int j = 0; j < n; j++)
    		{
    			if(grid[i][j] == 'S')
    				peoplei = i, peoplej = j;
    			else if(grid[i][j] == 'B')
    				boxi = i, boxj = j;
    			else if(grid[i][j] == 'T')
    				targetx = i, targety = j;
    		}
    	}
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	priority_queue<node, vector<node>, cmp> q; //push次数, box 和 people 的状态压成 4位 32 进制的 int
    	node state(0, boxi, boxj, peoplei, peoplej);
    	q.push(state);
    	set<node, cmp> vis;
    	vis.insert(state);
    	while(!q.empty())
    	{
    		int pj = q.top().pj;
    		int pi = q.top().pi;
    		int bj = q.top().bj;
    		int bi = q.top().bi;
    		push = q.top().push;
    		if(bi==targetx && bj==targety)
    			return push;
    		q.pop();
    		int disi = bi-pi;
    		int disj = bj-pj;
    		int nextbi, nextbj, nextpi, nextpj;
    		if(abs(disi)+abs(disj)==1)//人和箱子贴着了
    		{
    			nextbi = bi+disi;
    			nextbj = bj+disj;
    			state.bi = nextbi;
    			state.bj = nextbj;
    			state.pi = bi;
    			state.pj = bj;
    			state.push = push+1;
    			if(grid[nextbi][nextbj] != '#' && vis.find(state) == vis.end())
    			{	//box下一个位置不为墙
    				vis.insert(state);
    				q.push(state);
    			}
    		}
    		else// 人和箱子没有接触
    		{
    			for(int d = 0; d < 4; d++)
    			{
    				nextpi = pi+dir[d][0];
    				nextpj = pj+dir[d][1];
    				state.bi = bi;
	    			state.bj = bj;
	    			state.pi = nextpi;
	    			state.pj = nextpj;
	    			state.push = push;
    				if(grid[nextpi][nextpj] != '#' && vis.find(state) == vis.end())
    				{
    					vis.insert(state);
    					q.push(state);
    				}
    			}
    		}
    	}
    	return -1;
    }
};

// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#",".","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#","#","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#"],["#","T",".",".","#","#"],["#",".","#","B",".","#"],["#",".",".",".",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#","#"],["#","S","#",".","B","T","#"],["#","#","#","#","#","#","#"]]

// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#",".","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#","#","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#"],["#","T",".",".","#","#"],["#",".","#","B",".","#"],["#",".",".",".",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
// [["#","#","#","#","#","#","#"],["#","S","#",".","B","T","#"],["#","#","#","#","#","#","#"]]