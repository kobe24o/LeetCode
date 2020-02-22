int count(int n)
{
	int c = 0;
	while(n)
	{
		c++;
		n = n&(n-1);
	}
	return c;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
    	sort(arr.begin(), arr.end(),[](auto& a, auto& b) 
    			{if(count(a) == count(b))
    				return a < b;
    			return count(a) < count(b);});
    	return arr;
    }
};