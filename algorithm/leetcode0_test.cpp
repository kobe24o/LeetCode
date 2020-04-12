/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

class Solution {
    int lx2,rx2,by2,uy2;
    int lx1,rx1,by1,uy1;
    int dx1, dy1, dx2, dy2;
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        lx2 = min(start2[0],end2[0]);
        rx2 = max(start2[0],end2[0]);
        by2 = min(start2[1],end2[1]);
        uy2 = max(start2[1],end2[1]);
        lx1 = min(start1[0],end1[0]);
        rx1 = max(start1[0],end1[0]);
        by1 = min(start1[1],end1[1]);
        uy1 = max(start1[1],end1[1]);

        dx1 = start1[0]-end1[0];
        dy1 = start1[1]-end1[1];
        dx2 = start2[0]-end2[0];
        dy2 = start2[1]-end2[1];
        if(dx1*dy2==dx2*dy1)//平行
        {
            vector<vector<int>> ans;
            if(inline2(start1[0],start1[1],start2[0],start2[1]))
            {
                ans.push_back({start1[0],start1[1]});
            }
            if(inline2(end1[0],end1[1],start2[0],start2[1]))
            {
                ans.push_back({end1[0],end1[1]});
            }
            if(inline1(start2[0],start2[1],start1[0],start1[1]))
            {
                ans.push_back({start2[0],start2[1]});
            }
            if(inline1(end2[0],end2[1],start1[0],start1[1]))
            {
                ans.push_back({end2[0],end2[1]});
            }
            if(ans.size()>1)
                sort(ans.begin(), ans.end());
            if(ans.size())
                return {double(ans[0][0]),double(ans[0][1])};
            return {};
        }
        else
        {
            double x = double(dx1*dx2*(start2[1]-start1[1])+dx2*dy1*start1[0]-dx1*dy2*start2[0])/(dx2*dy1-dx1*dy2);
            double y = double(dy1*dy2*(start2[0]-start1[0])+dx1*dy2*start1[1]-dx2*dy1*start2[1])/(dx1*dy2-dx2*dy1);
            if(inline1(x,y,start1[0],start1[1])&&inline2(x,y,start2[0],start2[1]))
                return {x,y};
            return {};
        }

    }

    bool inline1(double x, double y, int x0, int y0)
    {
        return (lx1<=x && x<=rx1 && by1<=y && y<=uy1 && (abs(dx1*(y-y0)-dy1*(x-x0))<0.000001));
    }
    bool inline2(double x, double y, int x0, int y0)
    {
        return (lx2<=x && x<=rx2 && by2<=y && y<=uy2 && (abs(dx2*(y-y0)-dy2*(x-x0))<0.000001));
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<char>> v6 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {1,0};
    vector<int> v2 = {1,1};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"a","aa"};
    vector<string> st1 = {};
    Solution s;
    s.intersection(v1,v2,v3,v4);
    printv(v1);
    v1.resize(3);
    printv(v1);
    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;


    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}