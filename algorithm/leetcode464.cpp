class Solution {
    unordered_map<int,bool> m;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal)
            return false;//总和不够
        return win(maxChoosableInteger, desiredTotal, 0, 0);
    }
    bool win(int maxChoosableInteger, int desiredTotal, int point, int state) 
    {
        if(m.find(state) != m.end())
            return m[state];//重复的状态，直接读取
        for(int i = 1; i <= maxChoosableInteger; i++)
        {
            if(((state>>i)&1)==0)
            {   // 该二进制位为0 表示没有拿过该数
                if(point+i >= desiredTotal)
                    return true;
                int newstate = state | (1<<i);//新的状态，该位为1，用过了
                if(!win(maxChoosableInteger, desiredTotal, point+i, newstate))
                    return m[state] = true;
                    //上一个人在 newstate 下不能赢，那我在 state 状态下能赢
            }
        }
        return m[state] = false;
    }
};
