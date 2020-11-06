class Solution {
    bool ans = false;
    vector<char> ch = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        unordered_set<string> s(allowed.begin(), allowed.end());
        vector<vector<char>> gold(n, vector<char>(n, '*'));
        for(int j = 0; j < n; j++) 
        {
            gold[n-1][j] = bottom[j];//填充最底层的字母
        }
        dfs(gold, s, n-2, 0);//从倒数第二行，第0列，开始搜索
        return ans;
    }
    void dfs(vector<vector<char>>& gold, unordered_set<string>& s, int i, int j)
    {
        if(ans == true)
            return;
        char origin = gold[i][j];//记录原始字母
        for(int k = 0; k < 7; k++)//填入7种可能的字母
        {
            string t = string(1, gold[i+1][j])+gold[i+1][j+1]+char('A'+k);
            // 三元组字符串
            if(s.find(t) != s.end())//字符串在字典中
            {
                if(i == j)//这一行填完了
                {
                    if(i == 0)
                        ans = true;
                    gold[i][j] = char('A'+k);//填入可能的字母
                    dfs(gold, s, i-1, 0);//下一行，0列
                    gold[i][j] = origin;//恢复现场
                }
                else
                {
                    gold[i][j] = char('A'+k);
                    dfs(gold, s, i, j+1);//当前行，下一列
                    gold[i][j] = origin;
                }
            }
        }
    }
};