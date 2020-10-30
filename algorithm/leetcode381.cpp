class RandomizedCollection {
    vector<int> arr;
    unordered_map<int, unordered_set<int>> m;//数字对应的下标集合
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool exist = true;
        if(m.find(val) != m.end())
            exist = false;
        arr.push_back(val);
        m[val].insert(arr.size()-1);
        return exist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        int idx = *m[val].begin();
        m[val].erase(m[val].begin());
        if(m[val].empty())
            m.erase(val);
        int last = arr.back();
        m[last].insert(idx);//跟下一句顺序不能变，如果是同一位置就会出错
        m[last].erase(arr.size()-1); 
        if(m[last].empty())
            m.erase(last);
        arr[idx] = last;
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = random() % arr.size();
        return arr[idx];
    }
};