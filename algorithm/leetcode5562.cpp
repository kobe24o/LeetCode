class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> m;
        for(char c : s)
            m[c]++;//字符计数
        vector<int> num;
        for(auto& mi : m)
            num.push_back(mi.second);//频数
        sort(num.begin(), num.end());//频数排序
        set<int> set;
        int del = 0;
        for(int i = num.size()-1; i>=0; --i)
        {   // 从大的频数开始遍历
            if(!set.count(num[i]))
                set.insert(num[i]);//频数不存在，直接插入set
            else//频数存在，往下找不存在的频数
            {
                int k = num[i]-1;
                while(set.count(k))
                    k--;//找到一个 频数 k 是没有出现过的
                if(k > 0)//如果频数大于 0
                    set.insert(k);
                del += min(num[i], num[i]-k);//要删除的字符数
            }
        }
        return del;
    }
};