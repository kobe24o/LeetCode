class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size(), maxsum = INT_MIN;
        vector<int> arr(2*n);
        for(int i = 0; i < 2*n; ++i)
        {
            arr[i] = A[i%n];
            arr[i] += i>0 ? arr[i-1] : 0;//前缀和
        }
        //下面求最长长度n的子数组最大和
        deque<int> q;//存下标，队列内前缀和的值保持单调递增
        for(int i = 0; i < 2*n; ++i)
        {
            while(!q.empty() && i-q.front() > n)//距离超了的，删除
                q.pop_front();
            maxsum = max(maxsum, arr[i]-(q.empty() ? 0 : arr[q.front()]));
            
            while(!q.empty() && arr[q.back()] > arr[i])
                q.pop_back();
            q.push_back(i);
        }
        return maxsum;
    }
};