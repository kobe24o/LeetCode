class Solution {
	deque<deque<char>> ans = {{'_'}};
    					// 右  下  左  上
    vector<char> dirCh = {'R','D','L','U'};
public:
    vector<string> printKMoves(int K) {
        int x = 0, y = 0, d = 0, columns = 1, i = 0;
        while(K--)
        	update(x,y,d,columns);//更新k步的地图
        ans[x][y] = dirCh[d];//最后的位置填方向
        vector<string> res(ans.size());
        string str;
        for(auto& dq : ans)
        {
            str = "";
            for(char ch : dq)
                str += ch;
            res[i++] = str;
        }
        return res;
    }

    void update(int& x, int& y, int& d, int& columns) 
    {
    	char ch = ans[x][y];
    	ans[x][y] = (ch=='_' ? 'X' : '_');//反转颜色
    	d = (ch=='_' ? (d+1)%4 : (d+3)%4);//转向
    	if(d==0)//R
    	{
    		y++;
    		if(y == ans[x].size())//需要开新的地图，右侧加列
    		{
    			for(auto& s : ans)
    				s.push_back('_');
    			columns++;
    		}
    	}
    	else if(d==1)//D
    	{
    		x++;
    		if(x == ans.size())//需要开新的地图，下面加行
    			ans.push_back(deque<char>(columns,'_'));
    	}
    	else if(d==2)//L
    	{
    		y--;
    		if(y<0)//需要开新的地图，左侧加列
    		{
    			y = 0;
    			for(auto& s : ans)
    				s.push_front('_');
    			columns++;
    		}
    	}
    	else//U
    	{
    		x--;
    		if(x<0)//需要开新的地图，上面加行
    		{
    			x = 0;
    			ans.push_front(deque<char>(columns,'_'));
    		}
    	}
    }
};