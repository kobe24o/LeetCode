// class player
// {
// public:
// 	int id, score;
// 	player(int id, int score)
// 	{
// 		this->id = id;
// 		this->score = score;
// 	}
// };
struct cmp
{
	bool operator()(int a, int b) const
	{
		return a >= b;
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
    		// player* p = new player(playerId, score);
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
    	// topk.erase(m[playerId]);
    	// topk.insert(m[playerId]);
        // for(auto it = topk.begin(); it != topk.end(); ++it)
        // 	cout << (*it)->score << endl;
        // cout << "-----------" << endl;
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
        // topk.erase(m[playerId]->s)
    	m[playerId] = 0;
        topk.insert(0);
    	// topk.erase(m[playerId]);
    	// topk.insert(m[playerId]);
    	// for(auto it = topk.begin(); it != topk.end(); ++it)
        // 	cout << (*it)->score << endl;
        // cout << "-----------" << endl;
    }
};