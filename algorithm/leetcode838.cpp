- 先处理两边向外倒的
- 然后记录中间的位置，用正负号区分方向
- 遍历中间间隔的左右位置的符号，分四种情况（都向左，都向右，不动，向中间倒）
```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), L = 0, R = n-1, l=-1, r=-1, i;
        while(L < n && dominoes[L] != 'R')
        {
            if(dominoes[L]=='L')
                l = L;//左边连续的最后一个L(中间没有遇到R)
            L++;
        }
        while(R >= 0 && dominoes[R] != 'L')
        {
            if(dominoes[R]=='R')
                r = R;//右边连续的最后一个R(中间没有遇到L)
            R--;
        }
        if(l != -1)//左侧存在向左倒的
            for(i = l-1; i >= 0; i--)
                dominoes[i] = 'L';
        if(r != -1)//右侧存在向右倒的
            for(i = r+1; i < dominoes.size(); i++)
                dominoes[i] = 'R';
        vector<int> pos;//中间的LR的位置记录下来
        for(i = L; i <= R; ++i)
        {
            if(dominoes[i] == 'R')
                pos.push_back(i+1);//向右为+，+1为避免出现0
            else if(dominoes[i] == 'L')
                pos.push_back(-(i+1));//向左为 - 
        }
        for(i = 0; i < int(pos.size())-1; ++i)//遍历中间的隔间
        {
            if(pos[i] > 0 && pos[i+1] > 0)
            {//  右 右，中间还是右
                l = pos[i], r = pos[i+1]-1;
                while(l < r)
                    dominoes[l++] = 'R';
            }
            else if(pos[i] < 0 && pos[i+1] < 0)
            {   // 左， 左，中间还是左
                l = -pos[i], r = -pos[i+1]-1;
                while(l < r)
                    dominoes[l++] = 'L';
            }
            else if(pos[i] > 0 && pos[i+1] < 0)//向中间倒
            {   // 左边向右，右边向左，双指针遍历
                l = pos[i], r = -pos[i+1]-2;
                while(l < r)
                {
                    dominoes[l++] = 'R';
                    dominoes[r--] = 'L';
                }
            }
            //还有一种情况（左边向左，右边向右），中间不受影响
        }
        return dominoes;
    }
};
```
40 ms   11 MB

- 优化代码：在原字符串前面 + `L`，尾部 + `R`，最后答案舍去首尾即可，可以简化代码量

```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L'+dominoes+'R';
        int n = dominoes.size(), L = 0, R = n-1, l, r, i;
        vector<int> pos;//中间的LR的位置记录下来
        for(i = 0; i < n; ++i)
        {
            if(dominoes[i] == 'R')
                pos.push_back(i+1);//向右为+，+1为避免出现0
            else if(dominoes[i] == 'L')
                pos.push_back(-(i+1));//向左为 - 
        }
        for(i = 0; i < int(pos.size())-1; ++i)//遍历中间的隔间
        {
            if(pos[i] > 0 && pos[i+1] > 0)
            {//  右 右，中间还是右
                l = pos[i], r = pos[i+1]-1;
                while(l < r)
                    dominoes[l++] = 'R';
            }
            else if(pos[i] < 0 && pos[i+1] < 0)
            {   // 左， 左，中间还是左
                l = -pos[i], r = -pos[i+1]-1;
                while(l < r)
                    dominoes[l++] = 'L';
            }
            else if(pos[i] > 0 && pos[i+1] < 0)//向中间倒
            {   // 左边向右，右边向左，双指针遍历
                l = pos[i], r = -pos[i+1]-2;
                while(l < r)
                {
                    dominoes[l++] = 'R';
                    dominoes[r--] = 'L';
                }
            }
        }
        return dominoes.substr(1,n-2);
    }
};
```
36 ms   12.6 MB