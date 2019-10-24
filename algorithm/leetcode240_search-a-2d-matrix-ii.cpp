#include<vector>
using namespace std;
class Solution {
	int m,n;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size()==0 || matrix[0].size() == 0)
    		return false;
        int r = matrix.size(), c = matrix[0].size();
        m = r, n = c;
        int x1 = 0, y1 = 0, x2 = r-1, y2 = c-1, mx, my;
        bool ans = false;
    	return search(matrix,target,x1,y1,x2,y2,ans);
    }

    bool search(vector<vector<int>> &matrix, int &target, int x1, int y1, int x2, int y2, bool &ans)
    {
    	if(ans)
    		return true;
    	if(x1 > x2 || y1 > y2 ||x1<0||x1>=m||x2<0||x2>=m||y1<0||y1>=n||y2<0||y2>=n)
    		return false;
    	int mx = x1+((x2-x1)>>1);
    	int my = y1+((y2-y1)>>1);
    	if(matrix[mx][my] == target)
    		return true;
    	if(matrix[mx][my] < target)
    	{
    		return search(matrix,target,x1,my+1,mx,y2,ans)
    				|| search(matrix,target,mx+1,y1,x2,my,ans)
    				|| search(matrix,target,mx+1,my+1,x2,y2,ans);
    	}
    	else
    	{
    		return search(matrix,target,x1,my,mx-1,y2,ans)
    				|| search(matrix,target,mx,y1,x2,my-1,ans)
    				|| search(matrix,target,x1,y1,mx-1,my-1,ans);
    	}
    }
};

int main()
{
	vector<vector<int>> m = {
							  {1,   4,  7, 11, 15},
							  {2,   5,  8, 12, 19},
							  {3,   6,  9, 16, 22},
							  {10, 13, 14, 17, 24},
							  {18, 21, 23, 26, 30}
							};
	Solution s;
	s.searchMatrix(m,5);
}

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size()==0 || matrix[0].size() == 0)
//     		return false;
//         int r = matrix.size(), c = matrix[0].size();
//         int x = r-1, y = 0;
//         while(x>=0 && y<c)
//         {
//         	if(matrix[x][y] == target)
//         		return true;
//         	else if(matrix[x][y] < target)
//         		y++;
//         	else
//         		x--;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size()==0 || matrix[0].size() == 0)
//     		return false;
//         int r = matrix.size(), c = matrix[0].size();
//         int x = 0, y = c-1;
//         while(x<r && y>=0)
//         {
//         	if(matrix[x][y] == target)
//         		return true;
//         	else if(matrix[x][y] < target)
//         		x++;
//         	else
//         		y--;
//         }
//         return false;
//     }
// };