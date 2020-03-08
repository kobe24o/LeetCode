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
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), i, j, count = 0, rightLight = 0;
        vector<bool> leftallok(n,false);
        vector<bool> Lig(n,false);
        for(i = 0; i < n; ++i)
        {
            Lig[light[i]-1] = true;
            rightLight = max(rightLight, light[i]-1);
            if(light[i]-1 == 0)
                leftallok[0] = true;
            else
            {
                if(leftallok[light[i]-1-1])
                    leftallok[light[i]-1] = true;
            }
            if(leftallok[light[i]-1])
                for(j = light[i]; j <= rightLight; ++j)
                {
                    if(Lig[j])
                        leftallok[j];
                    else
                        break;
                }
            if(leftallok[rightLight])
                count++;
        }
        return count;
    }
};



int main() {
    Solution s;

    vector<int> v = {2,1,3,5,4};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    s.numTimesAllBlue(v);
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