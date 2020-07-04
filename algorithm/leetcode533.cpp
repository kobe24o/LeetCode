class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
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
    			if(picture[i][j]=='B' && r[i]==N && c[j]==N)
    				lonely++;
		return lonely;
    }
};