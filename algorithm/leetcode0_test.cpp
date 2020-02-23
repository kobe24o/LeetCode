/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int indegree[n]  = {0};
        int outdegree[n] = {0};
        bool findroot = false;
        int i, sum;
        for(i = 0; i < n; ++i)
        {
            if(leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if(rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }
        for(i = 0; i < n; ++i)
        {
            if(!findroot && indegree[i]==0)
                findroot = true;
            else if(findroot && indegree[i]==0)
                return false;
            else if(indegree[i] > 1)
                return false;
            sum += indegree[i];
        }
        if(sum != n-1)
            return false;
        return true;
    }
};
int main()
{
    Solution s;

    vector<int> l = {1,3,-1,-1,-1};
    vector<int> r ={-1,2,4,-1,-1};
    s.validateBinaryTreeNodes(5,l,r);


}