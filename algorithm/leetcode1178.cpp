class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // 处理 words 变成二进制位表示是否出现每种字符，转化成整数
        unordered_map<int, int> m;
        for(auto& w : words)
        {
            int v = 0;
            for(auto c : w)
                v |= 1<<(c-'a');
            m[v]++;
        }

        // 遍历谜面
        vector<int> ans(puzzles.size());
        for(int i = 0; i < puzzles.size(); ++i)
        {
            int bit = puzzles[i][0]-'a';//谜面的首字符位置
            int v = 0;
            for(auto c : puzzles[i])
                v |= 1<<(c-'a');
            // 枚举 v 的二进制状态子集
            for(int s = v; s>0; s = (s-1)&v)
            {
                if((s&(1<<bit)) && m.count(s))//状态包含谜面首字符
                    ans[i] += m[s];
            }
        }
        return ans;
    }
};