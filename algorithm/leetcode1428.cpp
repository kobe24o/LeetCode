/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m, n, i, j, left1col = INT_MAX, l, r, mid, mv;
        auto dim = binaryMatrix.dimensions();
        m = dim[0], n = dim[1];
        for(i = 0; i < m; ++i)
        {
        	l = 0, r = n-1;
        	while(l <= r)
        	{
        		mid = l+((r-l)>>1);
        		mv = binaryMatrix.get(i, mid);
        		if(mv==0)
        			l = mid+1;
        		else
        		{
        			if(mid==0 || binaryMatrix.get(i,mid-1)==0)
        			{
        				left1col = min(left1col, mid);
        				break;
        			}
        			else
        				r = mid-1;
        		}
        	}
        	if(left1col==0)
        		break;
        }
        return left1col==INT_MAX ? -1 : left1col;
    }
};

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m, n, i, j, left1col = INT_MAX, cur;
        auto dim = binaryMatrix.dimensions();
        m = dim[0], n = dim[1];
        i = m-1, j = n-1;//从右下角开始，右上角也行
        while(i >= 0 && j >= 0)
        {
            cur = binaryMatrix.get(i,j);
            if(cur==0)
                i--;//遇到0往上走
            else//遇到1
            {
                left1col = min(left1col, j);
                j--;//遇到1往左走
            }
            if(left1col==0)
                break;
        }
        return left1col==INT_MAX ? -1 : left1col;
    }
};