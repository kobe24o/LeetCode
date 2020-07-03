class ZigzagIterator {
    map<int, vector<int>> m;
    unordered_map<int,int> idx;
    int total = 0;
    map<int, vector<int>>::iterator it;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m[0] = v1;
        m[1] = v2;
        it = m.begin();
        idx[0] = 0;
        idx[1] = 0;
        total += v1.size()+v2.size();
    }

    int next() {
    	if(!hasNext())
    		return -1;
        if(it == m.end())
        	it = m.begin();
        if(idx[it->first] == it->second.size())
        {
            m.erase(it++);
            return next();
        }
        int val = it->second[idx[it->first]];
        idx[it->first]++;
        it++;
        total--;
        return val;
    }

    bool hasNext() {
        return total;
    }
};
