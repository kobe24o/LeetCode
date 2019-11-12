#include<vector>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node* r;
public:
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        r = build(grid,0,0,m-1,m-1);
        return r;
    }

    Node* build(vector<vector<int>>& grid, int sx, int sy, int ex, int ey) {
        if(sx == ex || sy == ey)//只有1个单元了，不能划分了
            return new Node(grid[sx][sy],true,0,0,0,0);
        int mx = (sx+ex)/2, my = (sy+ey)/2;
        Node *root = new Node(true,true,0,0,0,0);
        int b1, b2, b3, b4;//是全1？全0？两种都有？
        b1 = judge(grid,sx,sy,mx,my);
        b2 = judge(grid,sx,my+1,mx,ey);
        b3 = judge(grid,mx+1,sy,ex,my);
        b4 = judge(grid,mx+1,my+1,ex,ey);
        if(b1==1 && b2==1 && b3==1 && b4==1)
        {
            return root;
        }
        else if(b1==0 && b2==0 && b3==0 && b4==0)
        {
            root->val = false;
            return root;
        }
        else
        {
            root->isLeaf = false;
            root->topLeft = build(grid,sx,sy,mx,my);
            root->topRight = build(grid,sx,my+1,mx,ey);
            root->bottomLeft = build(grid,mx+1,sy,ex,my);
            root->bottomRight = build(grid,mx+1,my+1,ex,ey);
            return root;
        }
    }

    int judge(vector<vector<int>>& grid, int sx, int sy, int ex, int ey)
    {
        int i, j;
        bool allone = 1, allzero = 1;
        for(i = sx; i <= ex; ++i)
            for(j = sy; j <= ey; ++j)
                if(grid[i][j] == 0)
                {
                    allone = false;
                }
                else
                {
                    allzero = false;
                }
        if(allone^allzero)//全0或者全1
        {
            if(allone)
                return 1;//全1
            if(allzero)
                return 0;//全0
        }
        return -1;//0,1都有
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,1,1,1,0,0,0,0},
                             {1,1,1,1,0,0,0,0},
                             {1,1,1,1,1,1,1,1},
                             {1,1,1,1,1,1,1,1},
                             {1,1,1,1,0,0,0,0},
                             {1,1,1,1,0,0,0,0},
                             {1,1,1,1,0,0,0,0},
                             {1,1,1,1,0,0,0,0}};
    s.construct(v);
}