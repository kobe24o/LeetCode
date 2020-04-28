class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	unordered_set<int> s;
    	for(int Ai : A)
    		s.insert(Ai);
    	int a, b, c, len = 0, maxlen = 0;
    	for(int i = 0, j; i < A.size(); ++i)
    	{
    		for(j = i+1; j < A.size(); ++j)
    		{
                len = 2;
    			c = A[i]+A[j];
                a = A[i];
                b = A[j];
				while(s.count(c))
				{
					len++;
					maxlen = max(maxlen, len);
					a = b;
					b = c;
					c = a+b;
				}
    		}
    	}
    	return maxlen;
    }
};