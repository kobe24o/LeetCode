class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0}, maxNum = -1, sameWithMax = 0, len = tasks.size();
        for(char c:tasks)
        	count[c-'A']++;
        for(int i = 0; i < 26; i++)
        {
        	if(count[i] > maxNum)
        	{
        		maxNum = count[i];//数量最多的任务
        		sameWithMax = -1;
        	}
        	if(count[i] == maxNum)
        	{
        		sameWithMax++;//数量和最大的一样的(其他任务种类)
        	}
        }
        return max((maxNum-1)*n+maxNum+sameWithMax, len);
    }
};