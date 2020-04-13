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
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        if(square1[1] > square2[1])
            swap(square1,square2);//第一个的左下角y坐标更小
        double cx1, cy1, cx2, cy2, r1, r2;
        r1 = square1[2]/2.0;
        r2 = square2[2]/2.0;
        cx1 = square1[0]+r1;//中心坐标
        cy1 = square1[1]+r1;
        cx2 = square2[0]+r2;
        cy2 = square2[1]+r2;
        if(cx1==cx2)//斜率无穷大
            return {cx1,cy1-r1,cx1,max(cy1+r1,cy2+r2)};
        else//斜率存在,分两种情况，与上下边相交，左右边相交
        {
            double k = (cy1-cy2)/(cx1-cx2);
            double b = cy1-k*cx1;
            if(abs(k)>=1)//交点在上下边
            {
                if(k>0)
                    return {cx1-r1/k, cy1-r1, max(cx1+r1/k,cx2+r2/k),max(cy1+r1,cy2+r2)};
                else
                    return {min(cx1+r1/k,cx2+r2/k),max(cy1+r1,cy2+r2), cx1+r1/k, cy1-r1};
            }
            else//交点在左右边
            {
                if(square1[0] > square2[0])
                {
                    swap(square1,square2);//第一个的左下角x坐标更小
                    swap(r1,r2);
                    swap(cx1,cx2);
                    swap(cy1,cy2);
                }
                if(k>0)
                    return {cx1-r1,cy1-k*r1,max(cx1+r1,cx2+r2),max(cy1+k*r1,cy2+k*r2)};
                else
                    return {cx1-r1,cy1-k*r1,max(cx1+r1,cx2+r2),min(cy1-k*r1,cy2-k*r2)};
            }
        }
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
    vector<int> v1 = {68,130,64};
    vector<int> v2 = {-230,194,7};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"a","aa"};
    vector<string> st1 = {};
    Solution s;
    s.cutSquares(v1,v2);
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