class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    	int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    	int max1 = INT_MAX, max2 = INT_MAX, max3 = INT_MAX, max4 = INT_MAX;
    	for(int i = 0; i < arr1.size(); ++i)
    	{
    		max1 = max(max1, arr1[i] + arr2[i] + i);
    		max2 = max(max2,-arr1[i] - arr2[i] - i);
    		max3 = max(max3,-arr1[i] + arr2[i] + i);
    		max4 = max(max4, arr1[i] - arr2[i] + i);
    		min1 = min(min1, arr1[i] + arr2[i] - i);
    		min2 = min(min2,-arr1[i] - arr2[i] + i);
    		min3 = min(min3, arr1[i] - arr2[i] - i);
    		min4 = min(min4,-arr1[i] + arr2[i] - i);
    	}
    	return ;
    }
};