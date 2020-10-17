class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O = 0, winX = 0, winO = 0;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][j]=='X') X++;
                else if(board[i][j]=='O') O++;
            }
        if(X < O || X > O+1) return false;//个数差不对
        for(int i = 0; i < 3; ++i)
        {
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            {
                if(board[i][0] == 'X')
                    winX++;
                else if(board[i][0] == 'O')
                    winO++;
            }
        }
        for(int i = 0; i < 3; ++i)
        {
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            {
                if(board[0][i] == 'X')
                    winX++;
                else if(board[0][i] == 'O')
                    winO++;
            }
        }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        {
            if(board[0][0] == 'X')
                winX++;
            else if(board[0][0] == 'O')
                winO++;
        }
        if(board[2][0]==board[1][1] && board[1][1]==board[0][2])
        {
            if(board[2][0] == 'X')
                winX++;
            else if(board[2][0] == 'O')
                winO++;
        }
        if(X == O && winX)//先手赢，X == O+1
            return false;
        if(X != O && winO)//后手赢，X == O
            return false;
        return winX+winO==1 || ((winX==0 || winX==2) && winO==0);
                // 其中一人赢  或者  都没赢 或者 先手有2个可以赢的情况
    }
};