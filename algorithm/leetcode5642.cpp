class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int,long long> m;
        for(auto d : deliciousness)
            m[d]++;//计数
        long long ans = 0, mod = 1e9+7;
        for(int i = 0; i <= 22; i++)
        {	// 枚举 2的幂
            int target = 1 << i;
            for(auto it = m.begin(); it != m.end() && it->first <= target/2; ++it)
            {
                int d1 = target-it->first;//另一份餐的美味程度
                if(m.find(d1) == m.end())//不存在
                    continue;
                if(it->first != d1)//不相等
                    ans = (ans+it->second*m[d1])%mod;
                else//相等 Cn2
                    ans = (ans+m[d1]*(m[d1]-1)/2)%mod;
            }
        }
        return ans;
    }
};
