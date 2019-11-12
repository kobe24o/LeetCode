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
    Node* root;
public:
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        root = build(grid,0,0,m-1,m-1);
        return root;
    }

    Node* build(vector<vector<int>>& grid, int sx, int sy, int ex, int ey) {
        if(sx == ex || sy == ey)//只有1个单元了，不能划分了
            return NULL;
        int mx = (sx+ex)/2, my = (sy+ey)/2;
        root = new Node(false,false,0,0,0,0);
        bool b1, b2, b3, b4;//都是1吗？
        b1 = judge(grid,sx,sy,mx,my);
        b2 = judge(grid,sx,my+1,mx,ey);
        b3 = judge(grid,mx+1,sy,ex,my);
        b4 = judge(grid,mx+1,my+1,ex,ey);
        if(b1 && b2 && b3 && b4)
        {
            root->isLeaf = true;
            root->val = true;
        }
        else
        {
            root->isLeaf = false;
            root->topLeft = build(grid,sx,sy,mx-1,my-1);
            root->topRight = build(grid,sx,my,mx-1,ey);
            root->bottomLeft = build(grid,mx,sy,ex,my-1);
            root->bottomRight = build(grid,mx,my,ex,ey);
        }
        return root;
    }

    bool judge(vector<vector<int>>& grid, int sx, int sy, int ex, int ey)
    {
        int i, j;
        for(i = sx; i <= ex; ++i)
            for(j = sy; j <= ey; ++j)
                if(grid[i][j] == 0)
                    return false;
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,1,0,0},{1,1,0,1},{0,0,0,0},{0,0,0,0}};
    s.construct(v);
}