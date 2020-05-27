class Solution {    //超时
    vector<vector<int>> grid;
    int zero = 0, flips = 0, m, n;
    int x, y;
    bool foundZero;
public:
    Solution(int n_rows, int n_cols) {
        grid = vector<vector<int>> (n_rows, vector<int>(n_cols, 0));
        m = n_rows;
        n = n_cols;
    }
    
    vector<int> flip() {
        if(flips == m*n)
            return {};
        foundZero = false;
        zero = 0;
        for(int i = 0, j; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    continue;
                if(!foundZero)
                {
                    foundZero = true;
                    zero++;
                    x = i, y = j;
                }
                else//找到过了，每次以1/zero的概率替换
                {
                    if(rand()%zero == 0)
                        x = i, y = j;
                    zero++;
                }
            }
        }
        grid[x][y] = 1;
        flips++;
        return {x, y};
    }
    
    void reset() {
        grid = vector<vector<int>> (m, vector<int>(n, 0));
    }
};

class Solution {    //超时
    vector<int> grid;
    int m, n;
    int x, y, pos;
public:
    Solution(int n_rows, int n_cols) {
        grid = vector<int> (n_rows*n_cols, 0);
        m = n_rows;
        n = n_cols;
    }
    
    vector<int> flip() {
        do
        {
            pos = rand()%(m*n);
        }while(grid[pos] == 1);
        grid[pos] = 1;
        return {pos/n, pos-pos/n*n};
    }
    
    void reset() {
        grid = vector<int> (m*n, 0);
    }
};

class Solution {
    unordered_map<int,int> map;
    int m, n, num;
    int x, y, pos, prev;
public:
    Solution(int n_rows, int n_cols) {
        m = n_rows;
        n = n_cols;
        num = m*n;
    }
    
    vector<int> flip() {
        if(num == 0) return {};
        pos = rand()%(num);
        num--;//下一轮，减少一个数
        if(map.count(pos))//map包含pos的key
        {
            prev = pos;//记录当前pos
            pos = map[pos];//真实的取走的pos
            if(!map.count(num))//把最后一个位置的数换到当前
                map[prev] = num;
            else//如果最后一个位置有map值，用其值替换
                map[prev] = map[num];
        }
        else//map不包含pos的key
        {   //pos就是当前位置，只需把末尾的数替换到当前，同上
            if(!map.count(num))
                map[pos] = num;
            else
                map[pos] = map[num];
        }
        x = pos/n;
        y = pos-x*n;
        return {x, y};
    }
    
    void reset() {
        num = m*n;
        map.clear();
    }
};