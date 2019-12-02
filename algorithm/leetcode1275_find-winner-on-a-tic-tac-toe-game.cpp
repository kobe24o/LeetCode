class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> win = {0007,0070,0700,0444,0222,0111,0421,0124};
        int a = 0, b = 0, bit, i, j;
        bool flag = true;
        for(i = 0; i < moves.size(); i++) 
        {	//将整个棋盘看做9个2进制位
        	if(flag)//a先走
        	{
        		bit = moves[i][0]*3+moves[i][1];
        		a |= (1<<bit);
        		if(i >= 4)//走3步才可能赢
        		{
        			for(j = 0; j < 8; j++)
        				if((a&win[j]) == win[j])
        					return "A";
        		}
        	}
        	else
        	{
        		bit = moves[i][0]*3+moves[i][1];
        		b |= (1<<bit);
        		if(i >= 5)//走3步才可能赢
        		{
        			for(j = 0; j < 8; j++)
        				if((b&win[j]) == win[j])
        					return "B";
        		}
        	}
        	flag = !flag;//换人下棋
        }
        if(moves.size() < 9)
        	return "Pending";        	
    	return "Draw";
    }
};