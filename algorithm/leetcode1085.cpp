class Solution {
public:
    int sumOfDigits(vector<int>& A) {
    	int mina = *min_element(A.begin(),A.end());
    	int sum = 0;
    	while(mina)
    	{
    		sum += mina % 10;
    		mina /= 10;
    	}
    	return (sum&1) ? 0 : 1;
    }
};