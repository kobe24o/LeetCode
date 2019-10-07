class MyHashSet {
    bool *data;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = new bool[1000002];
        memset(data, 0, 1000002 * sizeof(bool));
    }
    
    void add(int key) {
        data[key] = 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */