class Solution {
public:
    int countArrangement(int N) {
        bool visited[N+1] = {false};//数字放过了吗
        int count = 0;
        bt(1,N,visited,count);
        return count;
    }

    void bt(int i, int &N, bool* visited, int &count)
    {
    	if(i == N+1)
    	{
    		count++;
    		return;
    	}
    	for(int num = 1; num <= N; ++num)
    	{
			if(!visited[num] && (num%i == 0 || i%num == 0))
			{
				visited[num] = true;
				bt(i+1, N, visited, count);
				visited[num] = false;
			}
    	}
    }
};