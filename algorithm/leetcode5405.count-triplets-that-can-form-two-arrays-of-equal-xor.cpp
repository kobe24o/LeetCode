class Solution {
public:
    int countTriplets(vector<int>& arr) {
    	vector<int> XOR(arr.size()+1,0);
    	int i, k, count = 0;
    	for(i = 1; i < XOR.size(); ++i)
    	{
    		XOR[i] = XOR[i-1]^arr[i-1];
    	}
    	for(i = 1; i < XOR.size(); ++i)
    	{
    		for(k = i+1; k < XOR.size(); ++k)
    		{
    			if(XOR[i-1] == XOR[k])
    				count += k-i;
    		}
    	}
    	return count;
    }
};