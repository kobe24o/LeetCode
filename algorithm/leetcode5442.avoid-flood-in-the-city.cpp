[我的博客](https://michael.blog.csdn.net/article/details/100577842)
```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        unordered_map<int,int> laker;//要抽水的湖泊数字, 对应的天idx
        deque<int> q;//可以抽水的天的编号idx
        for(int i = 0; i < rains.size(); ++i)
        {
            if(rains[i])//打雷了，下雨了，rains[i]号填满了
            {
                if(laker.find(rains[i]) == laker.end())
                    laker[rains[i]] = i;
                else//今天要下雨，这个湖有水，危险，我们要找之前的一天抽水
                {
                    int n = q.size();//n天可以选择
                    while(n-- && laker[rains[i]] > q.front())
                    {   //下雨的日期在可以抽水之后，干不了活
                        q.push_back(q.front());//挪到队尾，可能别的湖用得着，如[1,0,2,0,2,1]
                        q.pop_front();
                    }
                    if(q.empty() || laker[rains[i]] > q.front())//没有可以抽的时间
                        return {};//over
                    else
                    {
                        ans[q.front()] = rains[i];//找到下雨后的最近一天可以干活
                        q.pop_front();//干完了
                        laker[rains[i]] = i;//湖抽干了，今天的雨水可以放下，不危险了
                    }
                }
            }
            else//没有下雨，可以抽水
                q.push_back(i);
        }
        while(!q.empty())//没有干活的天，填上任意数字1-10e9，题目要求不等于-1
        {
            ans[q.front()] = 24;
            q.pop_front();
        }
        return ans;
    }
};
```

执行用时：580 ms
内存消耗：96.9 MB

or 

set 二分查找

```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        unordered_map<int,int> laker;//要抽水的湖泊数字, 对应的天idx
        set<int> s;
        for(int i = 0; i < rains.size(); ++i)
        {
            if(rains[i])//打雷了，下雨了，rains[i]号填满了
            {
                if(laker.find(rains[i]) == laker.end())
                    laker[rains[i]] = i;
                else//今天要下雨，这个湖有水，危险，我们要找之前的一天抽水
                {
                    auto it = s.lower_bound(laker[rains[i]]);//找到下雨后续的抽水天
                    if(it == s.end())//没找打
                        return {};
                    ans[*it] = rains[i];//后续的那天抽水
                    laker[rains[i]] = i;//更新当前的天数
                    s.erase(it);//抽完水了，删除
                }
            }
            else//没有下雨，可以抽水
                s.insert(i);
        }
        for(auto it = s.begin(); it != s.end(); ++it)
            ans[*it] = 1;//剩余的可抽水天填任意值
        return ans;
    }
};
```
696 ms  109.6 MB
[我的博客](https://michael.blog.csdn.net/article/details/100577842)