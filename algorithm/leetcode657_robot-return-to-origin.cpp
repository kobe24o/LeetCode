class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.size(); ++i)
        {
        	if(moves[i] == 'L')
        		x -= 1;
        	else if(moves[i] == 'R')
        		x += 1;
        	else if(moves[i] == 'U')
        		y += 1;
        	else
        		y -= 1;
        }
        if(!x && !y)
        	return true;
        return false;
    }
};