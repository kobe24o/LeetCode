class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
    	int sum = 0, mindis = INT_MAX, i;
    	for(i = 0; i < nuts.size(); ++i)
    		sum += 2*dis(tree[0],tree[1],nuts[i][0],nuts[i][1]);
    	for(i = 0; i < nuts.size(); ++i)
    		mindis = min(mindis, sum-dis(tree[0],tree[1],nuts[i][0],nuts[i][1])
                                +dis(squirrel[0],squirrel[1],nuts[i][0],nuts[i][1]));
    	return mindis;
    }
    int dis(int a, int b, int c, int d)
    {
    	return abs(a-c)+abs(b-d);
    }
};