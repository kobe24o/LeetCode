class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
    	int n = light.size(), i, j, count = 0, rightLight = 0;
    	vector<bool> leftallok(n,false);//左侧等都是亮的吗
    	vector<bool> Lig(n,false);//该位置灯亮了吗
    	for(i = 0; i < n; ++i)
    	{
    		Lig[light[i]-1] = true;//灯亮起来
    		rightLight = max(rightLight, light[i]-1);//最右侧的灯
    		if(light[i]-1 == 0)
    			leftallok[0] = true;//第一个灯的话，左边全亮
    		else
    		{
    			if(leftallok[light[i]-1-1])//左边灯全亮，那么到我这也全亮
    				leftallok[light[i]-1] = true;
    		}
    		if(leftallok[light[i]-1])//如果我这全亮的，向右检查挨着的是否亮
	    		for(j = light[i]; j <= rightLight; ++j)
	    		{
	    			if(Lig[j])//右边有亮的
	    				leftallok[j] = true;//到那里也是全亮
	    			else
	    				break;
	    		}
    		if(leftallok[rightLight])//最右侧的灯的左边全亮，计数+1
    			count++;
    	}
    	return count;
    }
};
