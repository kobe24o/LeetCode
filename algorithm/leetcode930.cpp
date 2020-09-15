class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
    	int n = A.size(), sum = 0, i = 0, count = 0;
    	unordered_map<int,int> m;
    	m[0] = 1;
    	for(i = 0; i < n; i++) 
    	{
    		sum += A[i];
    		if(m.find(sum-S) != m.end())
    			count += m[sum-S];
    		m[sum]++;
    	}
    	return count;
    }
};