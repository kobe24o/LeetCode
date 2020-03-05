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
    vector<vector<int>> ans;
    vector<int> path;
    int n;
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        // write your code here
        n = A.size();
        if(target <= 0)
            return {};
        sort(A.begin(), A.end());
        for(int i = 0; i <= n-k; ++i)
            dfs(A,i,0,k,0,target);
        // 	sort(ans.begin(),ans.end());
        // 	ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }

    void dfs(vector<int> &A, int idx, int count, int &k, int sum, int &target)
    {
        if(count == k)
        {
            if(sum == target)
                ans.push_back(path);
            return;
        }
        for(int i = idx; i < n; ++i)
        {
            path.push_back(A[i]);
            dfs(A,i+1,count+1,k,sum+A[i],target);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> v ={1,2,3,4};
    s.kSumII(v,2,5);
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