class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int bit, i, n = A.size(), carry = 0, sum;
        for(i = n-1; i >= 0 && K; --i)
        {
        	bit = K%10;
        	K /= 10;
        	sum = A[i]+bit+carry;
        	A[i] = sum%10;
        	carry = sum/10;
        }
        if(K == 0)
        {
        	while(i >= 0)
        	{
        		if(carry == 0)
        			break;
        		sum = A[i]+carry;
	        	A[i] = sum%10;
	        	carry = sum/10;
	        	i--;
        	}
        	if(i == -1 && carry)
        		A.insert(A.begin(),carry);
        }
        else//K不为0，数组遍历完了
        {
        	while(K || carry)
        	{
        		bit = K%10;
        		K /= 10;
        		sum = bit+carry;
        		carry = sum/10;
        		A.insert(A.begin(),sum%10);
        	}
        }
        return A;
    }
};