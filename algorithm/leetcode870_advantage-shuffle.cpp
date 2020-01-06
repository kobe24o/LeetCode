class Solution {
	int l,r,mid;
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> ans(A.size());
        int idx;
        for(int i = 0; i < B.size(); ++i)
        {
        	idx = binarysearch(A,B[i]);
        	if(idx != -1)
        	{
        		ans[i] = A[idx];
        		A.erase(A.begin()+idx);
        	}
        	else
        	{
        		ans[i] = A[0];
        		A.erase(A.begin());
        	}
        }
        return ans;
    }

    int binarysearch(vector<int>& A, int& n)
    {	//在A中找第一个比n大的
    	l = 0; r = A.size()-1;
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(A[mid] > n)
    		{
    			if(mid==0 || A[mid-1] <= n)
    				return mid;
    			r = mid-1;
    		}
    		else
    			l = mid+1;
    	}
    	return -1;
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        vector<vector<int>> Bval_idx(B.size(),{-1,-1});
        int n = A.size();
        for(int i = 0; i < n; ++i)
        {
        	Bval_idx[i][0] = B[i];
        	Bval_idx[i][1] = i;
        }
        sort(A.begin(), A.end());
        sort(Bval_idx.begin(), Bval_idx.end(), [](const auto& a, const auto& b)
        		{return a[0] < b[0];});//按数值排序
        int i = 0, j = n-1, k = 0;
        for(int k = 0; k < n; ++k)
        {
        	if(A[k] > Bval_idx[i][0])//最小的能打赢你的最小的
        	{
        		ans[Bval_idx[i++][1]] = A[k];
        	}
        	else//最小的不能打赢你们，那么送给你们最大的吃
        		ans[Bval_idx[j--][1]] = A[k];
        }
        return ans;
    }
};
