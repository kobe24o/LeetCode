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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = k-1, n = arr.size(), sum=0, target = k*threshold;
        set<vector<int>> s;
        for(i = 0; i < k; i++) { sum += arr[i];}
        if(sum >= target)
            s.insert(vector<int> (arr.begin(), arr.begin()+k));
        i++,j++;
        while(j < n)
        {
            sum += arr[j]-arr[i-1];
            if(sum >= target)
                s.insert(vector<int> (arr.begin()+i, arr.begin()+j+1));
            i++,j++;
        }
        return s.size();
    }
};
int main()
{
    Solution s;
    vector<int> v = {2,2,2,2,5,5,5,8};

    cout <<  s.numOfSubarrays(v,3,4);
}