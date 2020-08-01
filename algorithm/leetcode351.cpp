class Solution {
	vector<bool> visited;
public:
    int numberOfPatterns(int m, int n) {
    	int ans = 0;
    	for(int len = m; len <= n; ++len)
    	{
    		visited = vector<bool> (9, false);
    		ans += cal(-1,len);
    	}
    	return ans;
    }

    bool isok(int idx, int last)
    {
    	if(visited[idx]) return false;
    	if(last == -1) return true;//第一个数
    	if((idx+last)%2 == 1) return true;//相邻的两个数
    	int mid = (idx+last)/2;
    	if(mid == 4)//对角线的两个端点要连起来
    		return visited[mid];//看中点是否占用
    	if(idx%3 != last%3 && idx/3 != last/3)
    		return true;//不是 同行，或者 同列 的两个端点
    	return visited[mid];//检查0,6，中间是3，有没有被占用
    }
    int cal(int last, int len)
    {
    	if(len == 0) return 1;
    	int sum = 0;
    	for(int i = 0; i < 9; ++i)
    	{
    		if(isok(i, last))
    		{
    			visited[i] = true;
    			sum += cal(i, len-1);
    			visited[i] = false;
    		}
    	}
    	return sum;
    }
};