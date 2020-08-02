class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int i, j, sum = 0, n = grid.size(), ans = 0;
        vector<int> num;
        for(i = 0; i < n; ++i)
        {
            sum = 0;
            for(j = n-1; j>=0 && grid[i][j]==0 ; --j)
                sum++;
            num.push_back(sum);//末尾连续0的个数
        }
        for(i = 0; i < n; ++i)
        {
            if(num[i] >= n-i-1)
                continue;//0的个数够了，不动
            j = i;
            while(j < n && num[j] < n-i-1)
            {   //往下找到一个0够多的
                j++;
            }
            if(j == n)//没找到，返回-1
                return -1;
            while(num[i] < n-i-1)
            {   //找到了，往上挪
                swap(num[j], num[j-1]);
                ans++;
                j--;
            }
        }
        return ans;
    }
};