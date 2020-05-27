class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
    	unordered_map<int,int> m;//和，出现次数
    	m[0] = 1;
    	int count = 0, sum = 0;
    	for(int i = 0; i < A.size(); ++i)
    	{
    		sum += A[i]+10000*K;//+10000*K，防止负数
    		sum %= K;
    		count += m[sum];
    		m[sum]++;
    	}
    	return count;
    }
};