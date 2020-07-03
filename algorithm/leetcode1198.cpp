class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size();
    	int count[10001] = {0};
    	for(int j = 0, i; j < n; ++j)
    	{
    		for(i = 0; i < m; ++i)
    		{
    			if(++count[mat[i][j]] == m)
    				return mat[i][j];
    		}
    	}
    	return -1;
    }
};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size(), i = 0, cur = mat[0][0], count = 1;
    	vector<int> idx(m,0);//每行遍历到的位置
    	while(1)
    	{
            i = (i+1)%m;
            while(idx[i] < n && mat[i][idx[i]] < cur)
                idx[i]++;
            if(idx[i] >= n)
                return -1;
            else if(mat[i][idx[i]]==cur)
            {
                count++;
                idx[i]++;
            }
            else if(mat[i][idx[i]] > cur)
            {
                cur = mat[i][idx[i]];
                count = 1;
                idx[i]++;
            }
            if(count == m)
                return cur;
    	}
    	return -1;
    }
};