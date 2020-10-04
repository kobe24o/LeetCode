class ExamRoom {
	struct cmp
	{
		bool operator()(const pair<int,set<pair<int,int>>>& a, const pair<int,set<pair<int,int>>>& b) const
		{
			return a.first > b.first;//间距大的优先
		}
	};
	map<int,set<pair<int,int>>, cmp> m;// gap, set<l, r>区间端点
	unordered_map<int, pair<int,int>> neighbors;//记录某人左右的人是谁
public:
    ExamRoom(int N) {
    	m[N+1].insert(make_pair(-1, N));//加入虚拟边界
    }
    
    int seat() {
    	if(m.empty()) return -1;
    	auto it = m.begin();
    	int gap = it->first;
    	auto it1 = it->second.begin();
    	int l = it1->first, r = it1->second;
    	int ans = (l+r)/2;
    	neighbors[ans] = {l, r};
    	m[gap].erase(it1);
    	if(m[gap].empty())
    		m.erase(gap);
    	if(ans-l > 1)
    		m[ans-l].insert({l, ans});
    	if(r-ans > 1)
    		m[r-ans].insert({ans, r});
    	return ans;
    }
    
    void leave(int p) {
    	int l = neighbors[p].first;
    	int r = neighbors[p].second;
    	m[p-l].erase({l, p});
    	m[r-p].erase({p, r});
    	m[r-l].insert({l, r});
    }
};