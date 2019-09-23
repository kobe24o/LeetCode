bool cmp(vector<int> &a, vector<int> &b)
{
	return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),cmp);
        int count = 1;
        for(int i = 1; i < pairs.size(); ++i)
        {
        	if(pairs[i][0] > pairs[i-1][1])
        		++count;
        }
        return count;
    }
};