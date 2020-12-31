class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
    	int m = grid.size(), n = grid[0].size(), k = 21;
    	int targetx, targety, box, people, push = 0, size;
    	for(int i = 0; i < m; i++) 
    	{
    		for(int j = 0; j < n; j++)
    		{
    			if(grid[i][j] == 'S')
    				people = i*k+j;
    			else if(grid[i][j] == 'B')
    				box = i*k*k*k+j*k*k;
    			else if(grid[i][j] == 'T')
    				targetx = i, targety = j;
    		}
    	}
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	typedef pair<int, int> pii;
    	priority_queue<pii, vector<pii>, greater<pii>> q; //push次数, box 和 people 的状态压成 4位 32 进制的 int
    	q.push({0, box+people});
    	unordered_map<int,int> state_push;
    	state_push[box+people] = 0;
    	while(!q.empty())
    	{
    		int pj = q.top().second%k;
    		int pi = (q.top().second/k)%k;
    		int bj = (q.top().second/k/k)%k;
    		int bi = (q.top().second/k/k/k)%k;
    		push = q.top().first;
    		if(bi==targetx && bj==targety)
    			return push;
    		q.pop();
    		int disi = bi-pi;
    		int disj = bj-pj;
    		int nextbi, nextbj, nextpi, nextpj, state;
    		if(abs(disi)+abs(disj)==1)//人和箱子贴着了
    		{
    			nextbi = bi+disi;
    			nextbj = bj+disj;
    			if(grid[nextbi][nextbj] != '#')//box下一个位置不为墙
    			{
    				state = nextbi*k*k*k+nextbj*k*k+bi*k+bj;
    				if(state_push.find(state) == state_push.end() ||
    					state_push[state] > push+1)
    				{
    					state_push[state] = push+1;
    					q.push({state, push+1});
    				}
    			}
    		}
    		else// 人和箱子没有接触
    		{
    			for(int d = 0; d < 4; d++)
    			{
    				nextpi = pi+dir[d][0];
    				nextpj = pj+dir[d][1];
    				if(grid[nextpi][nextpj] != '#')
    				{
    					state = bi*k*k*k+bj*k*k+nextpi*k+nextpj;
    					if(state_push.find(state) == state_push.end() ||
    						state_push[state] > push)
    					{
    						state_push[state] = push;
    						q.push({state, push});
    					}
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