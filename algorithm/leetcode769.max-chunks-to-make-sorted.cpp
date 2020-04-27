class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int i, maxnum = 0, split = 0;
    	for(i = 0; i < arr.size(); ++i)
    	{
    		maxnum = max(maxnum, arr[i]);
    		if(maxnum == i)
    			split++;
    	}
    	return split;
    }
};