class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)
            return 0;
        int i, tp, prev = INT_MIN, step = 0, size;
        const int n = arr.size();
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = true;
        multimap<int, int> m;
        for(i = 0; i < n; i++)
        {
            if(arr[i] == prev)
                continue;//跳过一样的
            else//只插入连续相同的一段的首尾，中间跳肯定不是最短距离
            {  
                if(i-1>=0)
                    m.insert(make_pair(arr[i-1],i-1));
                m.insert(make_pair(arr[i], i));
                prev = arr[i];
            }
            if(i == n-1)//插入最后一个位置，可能重复插入了，但是不影响
                m.insert(make_pair(arr[i],i));
        }

        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                tp = q.front();
                q.pop();
                if(tp == n-1)
                    return step;

                // 跳往i+1位置
                if(tp+1 < n && !visited[tp+1])
                {
                    q.push(tp+1);
                    visited[tp+1] = true;
                }
                // 跳往i-1位置
                if(tp-1>0 && !visited[tp-1])
                {
                    q.push(tp-1);
                    visited[tp-1] = true;
                }
                
                // 跳往值相同的位置
                auto start = m.equal_range(arr[tp]).first, end = m.equal_range(arr[tp]).second;
                for(auto it = start; it != end; ++it)
                {
                    if(!visited[it->second])
                    {
                        visited[it->second] = true;
                        q.push(it->second);
                    }
                }
            }
            step++;
        }
        return step;
    }
};