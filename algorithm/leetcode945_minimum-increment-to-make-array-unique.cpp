class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    	map<int,int> m;
    	int count = 0;
    	for(int& a : A)
    		m[a]++;
    	for(auto& mi : m)
    	{
    		if(mi.second > 1)
    		{
    			count += mi.second-1;
    			m[mi.first+1] += mi.second-1;
    		}
    	}
    	return count;
    }
};

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int count = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i < A.size(); ++i)
        {
            if(A[i] <= A[i-1])
            {
                count += A[i-1]-A[i]+1;
                A[i] = A[i-1]+1;
            }
        }
        return count;
    }
};