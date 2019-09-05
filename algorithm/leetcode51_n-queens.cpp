class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string rowstr;
        vector<string> rowPos;
        vector<vector<string>> ans;
        int pos[n] = {0};
        solve(n,0,pos,rowstr,rowPos,ans);
        return ans;
    }
    void solve(int &n, int r, int *pos, string rowstr,vector<string> rowPos, vector<vector<string>> &ans)
    {
    	if(r == n)
    	{
    		ans.push_back(rowPos);
    		return;
    	}
    	int count, count2;
    	for(int c = 0; c < n; ++c)
    	{
    		if(ok(r,c,n,pos))
    		{
    			pos[r] = c;
    			count = count2 = n-c-1;
    			rowstr.push_back('Q');
    			while(count--)
    				rowstr.push_back('.');
    			rowPos.push_back(rowstr);
    			solve(n,r+1,pos,rowstr,rowPos,ans);
    			rowPos.pop_back();
    			while(count2--)
    				rowstr.pop_back();
    			rowstr.pop_back();
    		}
    		else
    			rowstr.push_back('.');
    	}	
    }
    bool ok(int &r, int &c, int &n, int *pos)
    {
    	int leftup = c - 1, rightup = c + 1;
        for(int i = r - 1; i >= 0; --i)//逐行向上考察每一行
        {
            if(pos[i] == c)//第i行的c列有棋子吗
                return false;
            if(leftup >= 0)//考察左上对角线
            {
                if(pos[i] == leftup)//第i行leftup列有棋子吗
                    return false;
            }
            if(rightup < n)//考察右上对角线
            {
                if(pos[i] == rightup)//第i行rightup列有棋子吗
                    return false;
            }
            --leftup; ++rightup;
        }
        return true;
    }
};