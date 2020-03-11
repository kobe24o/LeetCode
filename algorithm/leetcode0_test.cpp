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
    int M;
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        int maxsum = INT_MAX;
        int s = 0;
        for(int i = 0; i < nums.size(); ++i)
            s += nums[i];
        if(m==1)
            return min(maxsum,s);
        M=m;
        for(int i = 0; i <= nums.size()-m; i++)
        {
            int part1 = cut(nums,0,i,1);
            int part2 = cut(nums,i+1,nums.size()-1,m-1);

            maxsum = min(maxsum, max(part1,part2));
        }
        return maxsum;
    }

    int cut(vector<int> &nums,int l, int r, int m)
    {
        if(m == 1 || l==r)
        {
            return accumulate(nums.begin()+l, nums.begin()+r+1,0);
        }
        int partsum = INT_MAX, part1, part2;
        for(int i = l; i <= r+1-m; i++)
        {

            part1 = cut(nums,l,i,1);
            part2 = cut(nums,i+1,r,m-1);
            if(m==M)
                partsum = min(partsum,  max(part1,part2));
            else
                partsum = max(part1,part2);
        }


        return partsum;
    }
};



int main() {
    Solution s;

    vector<int> v = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    cout << s.splitArray(v,8) << endl;
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