class Solution {
	vector<vector<int>> dir ={{1,0},{0,1},{0,-1},{-1,0},{0,0}};//反转操作位置
	int m, n;
public:
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        int num = matToNum(mat), step = 0, size, i, j;
        if(num == 0)
        	return step;
        unordered_set<int> visited;//访问过了的状态
        queue<int> q;
        visited.insert(num);
        q.push(num);
        while(!q.empty())
        {
        	++step;//bfs步数
        	size = q.size();
        	while(size--)
        	{
        		numToMat(q.front(),mat);//将数字解码成矩阵mat
        		q.pop();
        		for(i = 0; i < m; i++)//mat的每个位置都可以操作
        		{
        			for(j = 0; j < n; j++)
        			{   //每个位置进行反转操作
        				flip(mat,i,j);
        				num = matToNum(mat);//将矩阵状态编码成num
        				if(num == 0)
        					return step;
        				if(!visited.count(num))//这种状态没有访问过
        				{
        					visited.insert(num);//访问标记
        					q.push(num);//加入队列
        				}
        				flip(mat,i,j);//恢复现场,进行下个位置反转
        			}
        		}
        	}
        }
        return -1;
    }

    int matToNum(vector<vector<int>>& M)
    {   //矩阵编码成数字
    	int num = 0, i, j;
    	for(i = 0; i < m; i++)
    		for(j = 0; j < n; j++)
    			num = num*2+M[i][j];
		return num;
    }

    void numToMat(int num, vector<vector<int>>& M)
    {   //数字解码成矩阵
    	int bit, i, j;
    	for(i = m-1; i >= 0; i--)
    		for(j = n-1; j >= 0; j--)
    		{
    			M[i][j] = (num&1);//取最低位
    			num >>= 1;//数字右移1位
    		}
    }

    void flip(vector<vector<int>>& M, int i, int j)
    {   //反转i,j位置，及其周围4个位置
    	int x, y, k;
    	for(k = 0; k < 5; k++)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n)
    			M[x][y] = 1-M[x][y];
    	}
    }
};