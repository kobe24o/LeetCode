class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size() == 0)
            return false;
        //在第一列搜索最后一个比我小的
        int i, r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r-1, mid;
        while(left <= right)
        {
        	mid = left + ((right-left)>>1);
        	if(matrix[mid][0] == target)
        		return true;
        	if(matrix[mid][0] < target)
        	{
        		if(mid == r-1 || matrix[mid+1][0] > target)
        			break;//mid行搜索即可
        		else
        			left = mid+1;
        	}
        	else
        		right = mid-1;
        }
        int R = mid;
        left = 0, right = c-1;
        while(left <= right)
        {
        	mid = left + ((right-left)>>1);
        	if(matrix[R][mid] == target)
        		return true;
        	if(matrix[R][mid] < target)     
        		left = mid+1;
        	else
        		right = mid-1;
        }
    	return false;
    }
};

class Solution {
	public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size()==0 || matrix[0].size() == 0)
	            return false;
	    int i, r = matrix.size(), c = matrix[0].size();

		// 二分查找
		int left = 0, right = r * c - 1;
		int mid, val;
		while (left <= right) 
		{
			mid = (left + right) / 2;
			val = matrix[mid/c][mid%c];
			if (target == val) 
				return true;
			else 
			{
				if (target < val) 
					right = mid - 1;
				else 
					left = mid + 1;
			}
		}
		return false;
	}
};