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
    string longestWord(vector<string>& words) {
        if(words.size() < 3)
            return "";
        sort(words.begin(), words.end(),[&](string a, string b){
            if(a.size() == b.size())
                return a < b;
            return a.size() > b.size();
        });
        int i, len;
        string ans, sub;
        unordered_set<string> set;
        for(i = 0; i < words.size(); ++i)
            set.insert(words[i]);
        for(i = 0; i < words.size()-1; ++i)
        {
            for(len = 1; len < words[i].size(); ++len)
            {
                sub = words[i].substr(0,len);
                if(set.count(sub) && ok(words[i].substr(len), set))
                    return words[i];
            }
        }
        return "";
    }

    bool ok(string s, unordered_set<string> &set)
    {
        if(s=="")
            return true;
        bool good = false;
        for(int len = 1; len <= s.size(); ++len)
        {
            string sub = s.substr(0,len);
            if(set.count(sub) && ok(s.substr(len),set))
            {
                good = true;
                break;
            }
        }
        return good;
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
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {12,13,15};
    vector<int> v3 = {100,150,90,190,95,110};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"a","aa"};
    vector<string> st1 = {};
    Solution s;
    s.longestWord(st);
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