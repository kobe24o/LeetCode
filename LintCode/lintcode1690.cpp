class Solution {
	int l,r,mid;
public:
    vector<int> getAns(vector<int> &val) {
        if(val.size() <= 1)
        	return {};
        vector<int> t;//二分插入数组
        t.push_back(val[0]);
        vector<int> ans(val.size()-1);
        int i, idx, k = 0, f, b;
        for(i = 1; i < val.size(); i++,k++)
        {
        	idx = bs(t,val[i]);//插入位置
    		t.insert(t.begin()+idx+1,val[i]);//插入数组
    		f = (idx >= 0 ? t[idx] : -10000000);//前面的性格值
    		b = (idx+2 < t.size() ? t[idx+2] : -10000000);//后面的性格值
    		if(abs(f-val[i]) <= abs(b-val[i]))
    			ans[k] = t[idx];//取较小的
    		else
    			ans[k] = t[idx+2];
        }
        return ans;
    }

    int bs(vector<int> & a, int& target)
    {	//二分查找，性格值小于等我的 最后一个
    	l = 0, r = a.size()-1;
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(a[mid] > target)
    			r = mid-1;
    		else //(a[mid] <= target)
    		{
    			if(mid==a.size()-1 || a[mid+1] > target)
    				return mid;
    			else
    				l = mid+1;
    		}
    	}
    	return -1;
    }
};