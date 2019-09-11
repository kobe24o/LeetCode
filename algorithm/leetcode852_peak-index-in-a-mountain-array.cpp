class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 1, right = A.size()-2, mid;
        while(left <= right)
        {
        	mid = left + ((right-left)>>1);
        	if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
        		return mid;
        	else if(A[mid] < A[mid+1])
        		left = mid+1;
        	else
        		right = mid-1;
        }
        return -1;
    }
};