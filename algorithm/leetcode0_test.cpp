/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> ans;
    int l,r,mid;
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        int idx;
        for(int i = 0; i < B.size(); ++i)
        {
            idx = binarysearch(A,B[i]);
            if(idx != -1)
            {
                ans[i] = A[idx];
                A.erase(A.begin()+idx);
            }
            else
            {
                ans[i] = A[0];
                A.erase(A.begin());
            }
        }
        return ans;
    }

    int binarysearch(vector<int>& A, int& n)
    {	//在A中找第一个比n大的
        l = 0; r = A.size()-1;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(A[mid] > n)
            {
                if(mid==0 || A[mid-1] <= n)
                    return mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> A={2,7,11,15}, B={1,10,4,11};
    s.advantageCount(A,B);
}