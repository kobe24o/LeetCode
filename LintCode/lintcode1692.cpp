class Solution {
public:
    int getAns(vector<int> &atk1, vector<int> &atk2) {
        //sort(atk1.begin(),atk1.end());
        sort(atk2.begin(),atk2.end());
        int i = 0, j = 0, count = 0;
        for(i = 0; i < atk1.size(); ++i)
        {
        	j = bs(atk2,atk1[i],0,atk2.size()-1);
        	if(j == -1)//没找到能打赢的
        		atk2.pop_back();//输给最强的吧，拉低怪兽的实力
        	else
        	{
        		count++;//能打赢，不能打个菜鸟吧，找个最强的
        		atk2.erase(atk2.begin()+j);
        	}
        }
        return count;
    }

    int bs(vector<int>& a, int &target, int l, int r)
    {	//二分查找小于 target 的最后一个
    	int mid;
    	while(l <= r)
    	{
    	    mid = l+((r-l)>>1);
    		if(a[mid] >= target)
    			r = mid-1;
    		else
    		{
    			if((mid==a.size()-1) || a[mid+1] >= target)
    				return mid;
    			else
    				l = mid+1;
    		}
    	}
    	return -1;
    }
};