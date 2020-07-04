class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
    	int m = picture.size(), n = picture[0].size(), i, j;
    	vector<int> r(m,0), c(n,0);
    	//对每行，每列的黑色进行计数
    	for(i = 0; i < m; ++i)
    		for(j = 0; j < n; ++j)
    			if(picture[i][j]=='B')
    				r[i]++, c[j]++;
		int lonely = 0;
		for(i = 0; i < m; ++i)
    		for(j = 0; j < n; ++j)
    			if(picture[i][j]=='B' && r[i]==1 && c[j]==1)
    				lonely++;
		return lonely;
    }
};