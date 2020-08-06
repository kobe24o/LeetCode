class Solution {
public:
    int shortestWay(string source, string target) {
    	int i = 0, j = 0, k, count = 0;
    	while(j < target.size())
    	{
    		k = j;
    		count++;
            i = 0;
    		while(i < source.size())
    		{
    			if(source[i] == target[j])
    			{
    				i++;
    				j++;
    			}
    			else
    				i++;//删除某字符
    		}
    		if(j == k)//没有填入一个字符到target
    			return -1;
    	}
    	return count;
    }
};