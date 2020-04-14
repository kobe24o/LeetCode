class Solution {
	vector<string> ans = {"_"};
    vector<vector<int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
    						// 右    下     左     上
    vector<char> dirCh = {'R','D','L','U'};
public:
    vector<string> printKMoves(int K) {
        int x = 0, y = 0, d = 0, count = 1
        while(K--)
        	update(x,y,d,count);
        ans[x][y] = dir[d];
        return ans;
    }

    void update(int& x, int& y, int& d, int& count) 
    {
    	char ch = ans[x][y];
    	ans[x][y] = (ch=='_' ? 'X' : '_');//反转颜色
    	d = (ch=='_' ? (d+1)%4 : (d+3)%4);//转向
    	
    }
};