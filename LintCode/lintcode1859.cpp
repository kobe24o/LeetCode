class Solution {
public:
    int MinimumAmplitude(vector<int> &A) {
    	if(A.size() <= 4)
    		return 0;
        sort(A.begin(),A.end());
        int j = A.size()-1;
        return min(A[j]-A[3],min(A[j-1]-A[2],min(A[j-2]-A[1], A[j-3]-A[0])));
    }
};

class Solution {
public:
    int MinimumAmplitude(vector<int> &A) {
    	if(A.size() <= 4)
    		return 0;
        sort(A.begin(),A.end());
        int Min = INT_MAX;
        int i = 3, j = A.size()-1, count = 4;
        while(count--)
        {
        	Min = min(Min, A[j]-A[i]);
        	j--,i--;
        }
        return Min;
    }
};