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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i, l, r, n = nums.size(), maxlen = 0, idx;
        vector<int> arr(nums);
        for(i = 0; i < n; ++i)
        {
            l = 0, r = maxlen;
            idx = bs(nums,arr,l,maxlen,nums[i],maxlen);
            if(idx == maxlen)
            {
                arr[idx+1] = nums[i];
                maxlen++;
            }
        }
        return maxlen;
    }

    int bs(vector<int>& nums, vector<int> &arr, int l, int r, int& target, int& maxlen)
    {
        int mid;
        while(l <= r)
        {
            mid = l + ((r-l)>>1);
            if(arr[mid] < target)
                l = mid+1;
            else
            {
                if(mid == maxlen || arr[mid+1] > target)
                    break;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {10,9,2,5,3,7,101,18};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{2,3}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    Solution s;
    s.lengthOfLIS(v1);

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