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
    int ratJump(vector<int> &arr) {
        int i, n = arr.size();
        long odd[n+3] = {0};
        long even[n+3] = {0};
        reverse(arr.begin(),arr.end());
        arr.push_back(0);
        arr.push_back(0);
        arr.push_back(0);
        // odd[0] = 1;
        even[0] = 1;
        if(arr[1]==0)
            odd[1] = 1;
        // if(arr[1]==0)
        // {
        // 	odd[1] = 1;
        // 	if(arr[0]==0)
        // 		even[1] = 1;
        // }
        for(i = 2; i < n+3; ++i)
        {
            odd[i] =  (i-1>=0 && i-1 < n-1 && arr[i-1]==0 && even[i-1]) ? even[i-1] : 0
                                                                                      + (i-2>=0 && i-2 < n-1 && arr[i-2]==0 && even[i-2]) ? even[i-2] : 0
                                                                                                                                                        + (i-4>=0 && i-4 < n-1 && arr[i-4]==0 && even[i-4]) ? even[i-4] : 0;
            odd[i] %= 1000000007;
            even[i] = (i-1>=0 && i-1 < n-1 && arr[i-1]==0 && odd[i-1]) ? odd[i-1] : 0
                                                                                    + (i-3>=0 && i-3 < n-1 && arr[i-3]==0 && odd[i-3]) ? odd[i-3] : 0
                                                                                                                                                    + (i-4>=0 && i-4 < n-1 && arr[i-4]==0 && odd[i-4]) ? odd[i-4] : 0;
            even[i] %= 1000000007;
        }
        long sum = 0;
        for(i = n-1; i < n+3; ++i)
        {
            sum += odd[i]+even[i];
            sum %= 1000000007;
        }
        return sum;
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9

int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {0,0,1,0};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<string> st  = {"T1S.",".*0*","....","..*."};
    Solution s;
    cout << s.ratJump(v1) << endl;

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left = t2;
    t2->right = t3;
    t3->left = t4;
    t3->right = t5;


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