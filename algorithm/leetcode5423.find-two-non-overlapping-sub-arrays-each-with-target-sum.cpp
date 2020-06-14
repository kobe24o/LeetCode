struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)const
    {
        return a.second-a.first < b.second-b.first;
        // 或者使用 set ，但是这里要加入 <= 号，但是这是个很不好的，
        // set就是去重的，你弄个相同的在里面，很让人迷惑
    }
};
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0, j=0, n = arr.size(), sum = 0;
        int minlen = INT_MAX;
        multiset<pair<int,int>,cmp> v;
        for(;j < n; ++j)
        {
            sum += arr[j];
            if(sum==target)
                v.insert({i,j});
            while(sum > target)
            {
                sum -= arr[i++];
                if(sum==target)
                    v.insert({i,j});
            }
            
        }
        for(auto it1 = v.begin(); it1 != v.end(); ++it1)
        {
            if(2*(it1->second-it1->first+1) >= minlen)
                break;//记得优化，容易超时
            auto it2 = it1;
            for(it2++; it2 != v.end(); ++it2)
            {
                if(it1->second < it2->first || it1->first > it2->second)
                {
                   minlen = min(minlen, it1->second - it1->first+it2->second - it2->first+2);
                   break;//找到了一个解，break，后面不会有更优的
                }
            }
        }
        return minlen==INT_MAX?-1:minlen;
    }
};

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i, n = arr.size(), sum = 0, minlen = INT_MAX;
        unordered_map<int,int> m;//前缀和，index
        m[0] = -1;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(i = 0; i < n; ++i)
        {
            sum += arr[i];
            m[sum] = i;
            if(m.count(sum-target))
            {
                minlen = min(minlen, i-m[sum-target]);
            }
            left[i] = minlen;
        }
        m.clear();
        m[0] = n;
        sum = 0;
        minlen = INT_MAX;
        for(i = n-1; i >= 0; --i)
        {
            sum += arr[i];
            m[sum] = i;
            if(m.count(sum-target))
            {
                minlen = min(minlen, m[sum-target]-i);
            }
            right[i] = minlen;
        }
        minlen = INT_MAX;
        for(i = 0; i < n-1; ++i)
            if(left[i]!=INT_MAX && right[i+1]!=INT_MAX)//左右都存在
                minlen = min(minlen, left[i]+right[i+1]);
        return minlen==INT_MAX?-1:minlen;
    }
};