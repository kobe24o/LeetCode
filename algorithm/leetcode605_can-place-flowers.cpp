class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	if(n == 0)
    		return true;
        int i = 0, count = 0, end = flowerbed.size()-1;
        bool prevFlower = false;//前面没有花
        bool nextFlower = false;//后面有没有花
        while(i <= end)
        {
        	if(flowerbed[i] == 0)//当前可以种花
        	{
        		nextFlower = (i==end ? false : flowerbed[i+1]);
        		prevFlower = (i==0 ? false : flowerbed[i-1]);
        		if(!prevFlower && !nextFlower)
        		{
        			flowerbed[i] = 1;//种上一朵花
        			count++;//计数+1
        			if(count == n)
        				return true;
        		}
        	}
        	++i;
        }
        return false;
    }
};