#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int i, j, x, y;
        unordered_map<int, int> m;
        for(i = 0; i < 9; ++i)
        {
            m.clear();
            for(j = 0; j < 9; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(m.find(board[i][j]-'0') != m.end())
                        return false;
                    else
                        m[board[i][j]-'0'] = 1;
                }
            }
        }
        for(j = 0; j < 9; ++j)
        {
            m.clear();
            for(i = 0; i < 9; ++i)
            {
                if(board[i][j] != '.')
                {
                    if(m.find(board[i][j]-'0') != m.end())
                        return false;
                    else
                        m[board[i][j]-'0'] = 1;
                }
            }
        }
        for(i = 0; i < 9; i += 3)
        {
            for(j = 0; j < 9; j += 3)
            {
                m.clear();
                for(x = i; x < i+3; ++x)
                {
                    for(y = j; y < j+3; ++y)
                    {
                        if(board[x][y] != '.')
                        {
                            if(m.find(board[x][y]-'0') != m.end())
                                return false;
                            else
                                m[board[x][y]-'0'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};