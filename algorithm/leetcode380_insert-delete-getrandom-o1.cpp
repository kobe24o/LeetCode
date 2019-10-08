class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end())
        {
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        v[m[val]] = v.back();
        m[v.back()] = m[val];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // srand((unsigned int) (time(NULL)));
        if(v.size() == 0)
            return -1;
        return v[rand() % v.size()];
    }
};