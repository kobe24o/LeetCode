struct cmp
{
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};
class Leaderboard {
	map<int,int> m;
	multiset<int, cmp> topk;
public:
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
    	if(m.find(playerId) == m.end())
    	{
    		m[playerId] = score;
            topk.insert(score);
    	}
    	else
    	{
            auto it = topk.find(m[playerId]);
            topk.erase(it);
            m[playerId] += score;
            topk.insert(m[playerId]);
        }
    }
    
    int top(int K) {
    	int sum = 0;
    	for(auto it = topk.begin(); it != topk.end() && K; ++it)
    	{
            K--;
    		sum += (*it);
    	}
    	return sum;
    }
    
    void reset(int playerId) {
        auto it = topk.find(m[playerId]);
        topk.erase(it);
    	m[playerId] = 0;
        topk.insert(0);
    }
};