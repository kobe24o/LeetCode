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

using namespace std;
class Solution {
public:
    int strToInt(string s) {
        int i, n = s.size();
        while(i < n && s[i] == ' ')
            i++;
        if(!isdigit(s[i]) && s[i] != '+' && s[i] != '-')
            return 0;
        long num = 0;
        bool negative = false;
        if(s[i] == '+')
            i++;
        else if(s[i] == '-')
        {
            negative = true;
            i++;
        }
        while(i < n && isdigit(s[i]))
        {
            num = num*10 + (negative ? -(s[i]-'0') : (s[i]-'0'));
            if(num >= INT_MAX)
                return INT_MAX;
            else if(num <= INT_MIN)
                return INT_MIN;
        }
        return num;
    }
};



int main() {
    Solution s;

    vector<int> v = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    cout << s.strToInt("-2.1e+10") << endl;
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
    return 0;
}