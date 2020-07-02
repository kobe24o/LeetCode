class Solution {
public:
    int missingNumber(vector<int>& arr) {
    	int maxgap = INT_MIN, gap, l, r;
    	for(int i = 0; i < arr.size()-1; ++i)
    	{
    		gap = arr[i+1]-arr[i];
    		if(abs(gap) > maxgap)
    		{
    			maxgap = abs(gap);
    			l = i, r = i+1;
    		}
    	}
    	return gap <= 0 ? arr[l]-maxgap/2 : arr[l]+maxgap/2;
    }
};