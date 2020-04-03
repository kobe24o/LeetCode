class Solution {
public:
    vector<int> subSort(vector<int>& array) {
    	vector<int> sortArray(array);
        sort(sortArray.begin(), sortArray.end());
        vector<int> ans;
        int i = 0;
        while(i < array.size() && array[i]==sortArray[i])
        	++i;
        if(i < array.size())
        	ans.push_back(i);
        i = array.size()-1;
        while(i >= 0 && array[i]==sortArray[i])
        	--i;
        if(i >= 0)
        	ans.push_back(i);
        if(ans.size()==2)
        	return ans;
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
    	if(array.size() < 2)
    		return {-1,-1};
    	int lmax = array[0], rmin = array[array.size()-1];
    	int left = -1, right = -1, n = array.size();
    	for(int i = 1; i < n; ++i)
    	{
    		if(array[i] < lmax)
    		{
    			if(left == -1)
    				left = i-1;
    		}
    		lmax = max(lmax, array[i]);
    		if(array[n-1-i] > rmin)
    		{
    			if(right == -1)
    				right = n-i;
    		}
    		rmin = min(rmin, array[n-1-i]);
    	}
    	return {left, right};
    }
};