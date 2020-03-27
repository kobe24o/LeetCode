class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());
    	if(a.back() <= b.front())
    		return b.front()-a.back();
    	if(b.back() <= a.front())
    		return a.front()-b.back();
    	int i = 0, j = 0, na = a.size(), nb = b.size(),mindis = INT_MAX;
        long diff;
    	while(i < na && j < nb)
    	{
            diff = a[i]-b[j];
            if(diff <= INT_MAX && diff > INT_MIN) 
                mindis = min(mindis, abs((int)diff));
    		if(a[i] <= b[j])
    			i++;
    		else
    			j++;
    	}
    	return mindis;
    }
};