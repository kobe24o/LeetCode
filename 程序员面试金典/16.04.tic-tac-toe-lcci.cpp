class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size(), i, j, count = 0;
        vector<int> ra(n,0);
        vector<int> ca(n,0);
        vector<int> rb(n,0);
        vector<int> cb(n,0);
        int xa1 = 0, xa2 = 0, xb1 = 0, xb2 = 0;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(board[i][j]=='X')
                {
                    ra[i]++;
                    ca[j]++;
                    if(i==j) xa1++;
                    if(i+j==n-1) xa2++;
                    count++;
                }
                else if(board[i][j]=='O')
                {
                    rb[i]++;
                    cb[j]++;
                    if(i==j) xb1++;
                    if(i+j==n-1) xb2++;
                    count++;
                }
            }
        }
        char win = '-';
        for(i = 0; i < n; ++i)
        {
            if(ra[i]==n || ca[i]==n ||xa1==n || xa2==n)
            {
                win = 'X';
                break;
            }
            if(rb[i]==n || cb[i]==n || xb1==n || xb2==n)
            {
                win = 'O';
                break;
            }
        }
        if(win=='X') return "X";
        if(win=='O') return "O";
        if(count == n*n) return "Draw";
        return "Pending";
    }
};