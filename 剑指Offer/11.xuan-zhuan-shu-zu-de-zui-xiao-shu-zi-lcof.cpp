class Solution {
public:
    int minArray(vector<int>& num) {
    	if(num.size()==1 || num[0] < num.back())
    		return num[0];
    	int l = 0, r = num.size()-1, mid;
    	while(l <= r) 
    	{
	    	mid = l +((r-l)>>1);
	    	//最小的肯定不在左侧
	    	if(num[mid] > num[r])
	    		l = mid+1;
	    	//mid右侧的肯定不是，mid可能是
	    	else if(num[mid] < num[r])
	    		r = mid;
	    	else//相等，r可以忽略，-1
	    		r--;
	    }
	    return num[l];
    }
};