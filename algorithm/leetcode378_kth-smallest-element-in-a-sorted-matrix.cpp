class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto row : matrix)
        	for(auto elem : row)
        		q.push(elem);
    	while(--k)
    		q.pop();
    	return q.top();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
    	int r = m.size(), c = m[0].size();
        int left = m[0][0], right = m[r-1][c-1], mid, count;
        while(left < right)
        {
        	mid = left+((right-left)>>1);
        	count = findNotBigerThanMid(m,mid,r,c);
        	if(count < k)
        		left = mid+1;
        	else
        		right = mid;
        }
        return left;
    }

    int findNotBigerThanMid(vector<vector<int>> &m, int &mid, int &r, int &c)
    {
    	int i = r-1, j = 0, count = 0;
    	while(i >= 0 && j < c)
    	{
    		if(m[i][j] <= mid)
    		{
    			count += i+1;
    			j++;
    		}
    		else
    			i--;
    	}
    	return count;
    }
};