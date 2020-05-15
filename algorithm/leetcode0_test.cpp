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
    bool circularArrayLoop(vector<int>& nums) {
        int i, idx, next, n = nums.size();
        int dir0_flag = 1000, dir1_flag = -1000, count = 0;
        for(i = 0; i < n; ++i)
        {
            if(nums[i] <= 1000 && nums[i] >= -1000)
            {
                idx = i;
                count = 1;
                if(nums[idx] > 0)
                {
                    dir0_flag++;
                    next = (idx+nums[idx])%n;
                    nums[idx] = dir0_flag;
                    idx = next;
                    while(nums[idx] > 0 && nums[idx] <= 1000)
                    {
                        next = (idx+nums[idx])%n;
                        nums[idx] = dir0_flag;
                        count++;
                        idx = next;
                    }
                    if(nums[idx] == dir0_flag && count > 1)
                        return true;
                }
                else// (nums[idx] < 0)
                {
                    dir1_flag--;
                    next = (idx+nums[idx]+n)%n;
                    nums[idx] = dir1_flag;
                    idx = next;
                    while(nums[idx] < 0 && nums[idx] >= -1000)
                    {
                        next = (idx+nums[idx]+n)%n;
                        nums[idx] = dir1_flag;
                        idx = next;
                    }
                    if(nums[idx] == dir1_flag && count > 1)
                        return true;
                }
            }
        }
        return false;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{5,3},{3,0},{5,1},{1,1},{1,5},{3,0},{0,2}};
    vector<vector<int>> v5 ={{1,2},{0,3},{0,3},{1,2}};
    vector<int> v1 = {2,5,1,1,1,1};
    vector<int> v2 = {1,3,5};
    vector<int> v3 = {-1,-2,-3,-4,-5};
    vector<int> v4 = {2,-1,1,2,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {};
    Solution s;
    s.circularArrayLoop(v3);
    printv(v4);

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