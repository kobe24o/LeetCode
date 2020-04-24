class DisjointSet
{
public:
	vector<int> father;
	DisjointSet(int n)
	{
		father.resize(n);
		for(int i = 0; i < n; ++i)
			father[i] = i;//并查集初始化
	}
	int find(int x)
	{
		if(x == father[x])
			return x;
		return father[x] = find(father[x]);
	}
	void merge(int x, int y)
	{
		int fx = find(x);
		int fy = find(y);
		if(fx != fy)
			father[fx] = fy;
	}
	int countUni()//计算有多少个团体
	{
		int count = 0;
		for(int i = 0; i < father.size(); ++i)
			if(find(i) == i)
				count++;
		return count;
	}
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
    	int n = grid.size(), i, j, pos;
    	DisjointSet uni(4*n*n);//一个位置分成4块，上下左右，共计这么多个单元
    	char ch;
    	for(i = 0; i < n; ++i)
    	{
    		for(j = 0; j < n; ++j)
    		{
    			pos = 4*(i*n+j);//单元格0位
    			ch = grid[i][j];
    			if(ch != '/')//为红线或者空白
    			{
    				uni.merge(pos+0,pos+1);
    				uni.merge(pos+2,pos+3);
    			}
    			if(ch != '\\')//为橙线线或者空白
    			{
    				uni.merge(pos+0,pos+3);
    				uni.merge(pos+2,pos+1);
    			}
    			if(i > 0)//上面合并
    				uni.merge(pos+0, pos-4*n+2);
    			if(i < n-1)//下面合并
    				uni.merge(pos+2, pos+4*n+0);
    			if(j > 0)//左面合并
    				uni.merge(pos+3, pos-4+1);
    			if(j < n-1)//右面合并
    				uni.merge(pos+1, pos+4+3);
    		}
    	}
    	return uni.countUni();
    }
};