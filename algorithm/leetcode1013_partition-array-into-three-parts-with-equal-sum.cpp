class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, i;
        for(i = 0; i < A.size(); ++i)
        	sum += A[i];
        if(sum%3)
        	return false;
        int part1of3 = sum/3;
        sum = 0;
        bool cut1 = false, cut2 = false;
        for(i = 0; i < A.size(); ++i)
        {
        	sum += A[i];
        	if(sum == part1of3 && !cut1)
        	{
        		cut1 = true;
        		sum = 0;
        	}
        	else if(sum == part1of3 && cut1)
        		return true;
        }
        return false;
    }
};