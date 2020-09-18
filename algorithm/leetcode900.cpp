class RLEIterator {
	vector<int> arr;
	vector<int> count;
	int idx = 0;
	int val;
public:
    RLEIterator(vector<int>& A) {
    	int n = A.size();
    	arr.resize(n/2);
    	count.resize(n/2);
    	for(int i = 1; i < A.size(); i += 2)
    	{
    		count[i/2] = A[i-1];
    		arr[i/2] = A[i];
    	}
    }
    
    int next(int n) {
    	val = -1;
    	while(idx < count.size() && n > 0)
    	{
    		if(count[idx] > n)
    		{
    			count[idx] -= n;
    			return arr[idx];
    		}
    		else
    		{
    			n -= count[idx];
    			if(n == 0)
    				val = arr[idx];
    			idx++;
    		}
    	}
    	return val;
    }
};