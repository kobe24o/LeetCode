#include <vector>
#include <unordered_map>
using namespace std;
//class Solution//暴力3次遍历
//{
//public:
//    bool isValidSudoku(vector<vector<char>>& board)
//    {
//        int i, j, x, y;
//        unordered_map<int, int> m;
//        for(i = 0; i < 9; ++i)
//        {
//            m.clear();
//            for(j = 0; j < 9; ++j)
//            {
//                if(board[i][j] != '.')
//                {
//                    if(m.find(board[i][j]-'0') != m.end())
//                        return false;
//                    else
//                        m[board[i][j]-'0'] = 1;
//                }
//            }
//        }
//        for(j = 0; j < 9; ++j)
//        {
//            m.clear();
//            for(i = 0; i < 9; ++i)
//            {
//                if(board[i][j] != '.')
//                {
//                    if(m.find(board[i][j]-'0') != m.end())
//                        return false;
//                    else
//                        m[board[i][j]-'0'] = 1;
//                }
//            }
//        }
//        for(i = 0; i < 9; i += 3)
//        {
//            for(j = 0; j < 9; j += 3)
//            {
//                m.clear();
//                for(x = i; x < i+3; ++x)
//                {
//                    for(y = j; y < j+3; ++y)
//                    {
//                        if(board[x][y] != '.')
//                        {
//                            if(m.find(board[x][y]-'0') != m.end())
//                                return false;
//                            else
//                                m[board[x][y]-'0'] = 1;
//                        }
//                    }
//                }
//            }
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, int> row[9];
        unordered_map<int, int> column[9];
        unordered_map<int, int> box[9];
        int i, j, box_idx, num;
        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j)
            {
                box_idx = (i/3)*3 + j/3;
                num = board[i][j] - '0';
                if(board[i][j] != '.')
                {
                    if(row[i].find(num) != row[i].end() ||
                        column[j].find(num) != column[j].end() ||
                        box[box_idx].find(num) != box[box_idx].end())
                        return false;
                    else
                    {
                        row[i][num] = 1;
                        column[j][num] = 1;
                        box[box_idx][num] = 1;
                    }
                }
            }
        }
        return true;
    }
};