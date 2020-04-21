class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	vector<int> presum(A.size()+1,0);
    	int i, minLen = INT_MAX, sum = 0;
    	deque<int> q;//存储下标，按照队内presum升序
    	q.push_back(0);
    	for(i = 0; i < A.size(); ++i)
    	{
    		presum[i+1] = presum[i] + A[i];
    		while(!q.empty() && presum[q.back()] >= presum[i+1])
    			q.pop_back();
    		while(!q.empty() && (presum[i+1]-presum[q.front()] >= K))
    		{
    			minLen = min(minLen, i+1-q.front());
    			q.pop_front();
    		}
    		q.push_back(i+1);
    	}
    	if(minLen == INT_MAX)
    		return -1;
    	return minLen;
    }
};