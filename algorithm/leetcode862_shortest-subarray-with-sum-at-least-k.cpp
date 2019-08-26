#include <climits>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	if(A.empty())
    		return -1;
    	int i, i_temp, j, cursum = 0, tempsum, minLen = INT_MAX;
        i = 0, j = 1;
        if(A[0] >= K)
        	return 1;
        else
    		cursum = A[0];
        while(j < A.size())
        {
        	if(cursum+A[j] >= K)
        	{
        		cursum += A[j];
        		if(minLen > j-i+1)
        			minLen = j-i+1;
                i_temp = i;
                tempsum = cursum;
        		while(i < j)
        		{
        		    if(cursum-A[i] >= K)
                    {
        		        cursum -= A[i];
                        ++i;
                        i_temp = i;
                        tempsum = cursum;
                        if(minLen > j-i+1)
                            minLen = j-i+1;
                    }
        		    else
                    {
        		        cursum -= A[i];
        		        ++i;
                    }

        		}
        		i = i_temp;
        		cursum = tempsum;
        		++j;
        	}
        	else
        	{
        	    cursum += A[j];
        	    ++j;
        	}
        }
        if(minLen != INT_MAX)
        	return minLen;
        else
        	return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-28,81,-20,28,-29};
    cout << s.shortestSubarray(v,89);
    return 0;
}