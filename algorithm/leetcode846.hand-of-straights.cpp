class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
    	int i, n = hand.size(), prev, count = 0;
    	if(n%W) return false;
    	if(W == 1) return true;
        map<int,int> m;
        for(i = 0; i < n; ++i)
        	m[hand[i]]++;
        auto it = m.begin();
        for(i = 0; i < n; ++i)
        {
    		if(count != 0 && it->first - prev != 1)
    			return false;
    		prev = it->first;
    		m[prev]--;
    		if(m[prev] == 0)
    			m.erase(it++);
    		else
    			it++;
    		if(it == m.end())
    			it = m.begin();
    		count++;
    		if(count == W)
    		{
    			count = 0;
    			it = m.begin();
    		}
        }
        return true;
    }
};