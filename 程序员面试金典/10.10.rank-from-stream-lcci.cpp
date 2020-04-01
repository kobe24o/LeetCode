class StreamRank {
	map<int,int> m;
	int count = 0;
public:
    StreamRank() {}
    
    void track(int x) {
    	m[x]++;
    }
    
    int getRankOfNumber(int x) {
    	count = 0;
    	for(auto& mi : m)
    	{
    		if(x >= mi.first)
    			count += mi.second;
    		else
    			break;
    	}
    	return count;
    }
};
class StreamRank {
	map<int,int> m;
public:
    StreamRank() {}
    
    void track(int x) {
        auto it = m.rbegin();
		for(; it != m.rend(); ++it)
		{
			if(it->first > x)
				it->second++;//有比x大的，他们的value（比它小的个数） +1
			else
				break;
		}
        if(it == m.rend() || (it != m.rend() && it->first == x))
            m[x]++; // map遍历到头了，x不存在，或者x存在
        else
            m[x] = it->second + 1;//遍历没到头，x不存在，x 的 value = 前一个value + 自己
    }
    
    int getRankOfNumber(int x) {
    	if(m.empty() || x < m.begin()->first)
    		return 0;
    	if(m.count(x))
    		return m[x];
    	auto end = m.upper_bound(x);
    	end--;
    	return end->second;
    }
};

class StreamRank {
    vector<int> v;
    int N = 50002;
public:
    StreamRank() {
        v = vector<int>(N);
    }
    
    void track(int x) {
        update(x+1, 1);
    }
    
    int getRankOfNumber(int x) {
        return query(x+1);
    }
    //-----树状数组-------
    int lowbit(int x)
    {
        return x&(-x);
    }
    void update(int i, int delta)
    {
        for( ; i < N; i += lowbit(i))
            v[i] += delta;
    }
    int query(int i)
    {
        int sum = 0;
        for( ; i > 0; i -= lowbit(i))
            sum += v[i];
        return sum;
    }
};