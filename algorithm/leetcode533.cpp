class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size(), n = picture[0].size(), i, j;
        vector<int> r(m,0), c(n,0);
        //对每行，每列的黑色进行计数
        //对一样的行，放到一起
        unordered_map<string,unordered_set<int>> map;
        string line;
        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                line += picture[i][j];
                if(picture[i][j]=='B')
                    r[i]++, c[j]++;
            }
            map[line].insert(i);//一样的行，放一起
            line = "";
        }
        int lonely = 0, l;
        for(auto it = map.begin(); it != map.end(); ++it)
        {   //遍历相同的行的集合
            l = *(it->second.begin());//其中一行
            for(j = 0; j < n; ++j)
            {   //遍历其列
                if(picture[l][j]=='B' && r[l]==N && c[j]==N && N==it->second.size())
                    lonely += N;//这一列中有N个黑色
            }
        }
        return lonely;
    }
};