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

class RLEIterator {
	vector<int> arr;
	vector<long long> count;
	long long totalcount = 0;
public:
    RLEIterator(vector<int>& A) {
    	for(int i = 1; i < A.size(); i += 2)
    	{
    		if(A[i-1] == 0)//数量为0，跳过 
    			continue;
    		totalcount += A[i-1];
    		count.push_back(totalcount);
    		arr.push_back(A[i]);
    	}
    	totalcount = 0;//重置
    }
    
    int next(int n) {
    	totalcount += n; // 二分查找大于等于 totalcount 的第一个元素
    	int l = 0, r = arr.size()-1, mid;
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(count[mid] < totalcount)
    			l = mid+1;
    		else
    		{
    			if(mid == 0 || count[mid-1] < totalcount)
    				return arr[mid];
    			else
    				r = mid-1;
    		}
    	}
    	return -1;
    }
};