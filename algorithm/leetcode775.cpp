class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
    	set<int> s;
    	s.insert(A[0]);
    	for(int i = 2; i < A.size(); ++i)
    	{
    		if(s.lower_bound(A[i]+1) != s.end())
    		{
    			return false;
    		}
    		s.insert(A[i-1]);
    	}
    	return true;
    }
};

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
    	int MAX = A[0];
    	for(int i = 2; i < A.size(); ++i)
    	{
    		if(MAX > A[i])
    			return false;
    		MAX = max(MAX, A[i-1]);
    	}
    	return true;
    }
};

class Solution {
	int local = 0, global = 0;
	vector<int> tmp;
public:
    bool isIdealPermutation(vector<int>& A) {
    	if(A.size() <= 1) return true;
    	for(int i = 0; i < A.size()-1; ++i)
    		if(A[i] > A[i+1])
    			local++;
    	tmp.resize(A.size());
    	mergesort(A, 0, A.size()-1);
    	return local == global;
    }
    void mergesort(vector<int>& A, int l, int r)
    {
    	if(l >= r) return;
    	int mid = (l+r)/2;
    	mergesort(A, l, mid);
    	mergesort(A, mid+1, r);
    	int i = l, j = mid+1, k = 0;
    	while(i <= mid && j <= r)
    	{
    		if(A[i] <= A[j])
    			tmp[k++] = A[i++];
    		else//前面没出队的比后面已经出来的都大
    		{
    			tmp[k++] = A[j++];
    			global += mid-i+1;
    		}
    	}
    	while(i <= mid)
            tmp[k++] = A[i++];
    	while(j <= r)
    		tmp[k++] = A[j++];
    	k = 0; i = l;
    	while(i <= r)
    		A[i++] = tmp[k++];
    }
};