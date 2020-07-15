/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i, j, count, ans = -1;
        bool famous;
        for(i = 0; i < n; ++i)
        {
        	famous = true;
        	count = 1;//自己认识自己
        	for(j = 0; j < n; ++j)
        	{
        		if(i == j)
        			continue;
        		if(knows(j, i))//j 认识 i
        			count++;
        		if(count < j+1)//有人不认识 i
        			break;//不是名人
        		if(knows(i,j))//他还认识别人,不是名人
        		{
        			famous = false;
        			break;
        		}
        	}
        	if(famous && count == n)//都认识他
        	{
        		ans = i;
        		break;
        	}
        }
        return ans;
    }
};

class Solution {
public:
    int findCelebrity(int n) {
    	int ans = 0;
        for(int i = 1; i < n; ++i)
        {
        	if(knows(ans, i))//认识i,ans不是名人
        		ans = i;
        }
        for(int i = 0; i < n; ++i)
        {
        	if(ans == i) continue;
        	if(knows(ans, i) || !knows(i, ans))//认识别人或者有人不认识他
        		return -1;
        }
        return ans;
    }
};