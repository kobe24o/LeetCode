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
    /**
     * @param atk1: the power of heros
     * @param atk2: the power of monsters
     * @return: how many monsters can you kill at most?
     */
    int getAns(vector<int> &atk1, vector<int> &atk2) {
        sort(atk1.begin(),atk1.end());
        sort(atk2.begin(),atk2.end());
        int i = 0, j = 0, count = 0;
        for(i = 0; i < atk1.size(); ++i)
        {
            cout << atk1[i] << " ";
            j = bs(atk2,atk1[i],0,atk2.size()-1);
            if(j == -1){
                cout << atk2.back() << "fail " << endl;
                atk2.pop_back();
            }
            else
            {
                count++;
                cout << *(atk2.begin()+j) << " win" << endl;
                atk2.erase(atk2.begin()+j);
            }
        }
        return count;
    }

    int bs(vector<int>& a, int &target, int l, int r)
    {
        int mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(a[mid] > target)
                r = mid-1;
            else
            {
                if((mid==a.size()-1) || a[mid+1] > target)
                    return mid;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};


int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {17,17,37,20,35,21,33,16,3,45};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{2,3}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    Solution s;
    s.getAns(v1,v3);

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