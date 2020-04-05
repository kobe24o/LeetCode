class node{
public:
	int k, v, f;
	node(int key, int val, int freq):k(key),v(val),f(freq){}
};
class LFUCache {
	unordered_map<int, list<node>::iterator> key_table;
    unordered_map<int, list<node>> freq_table;
public:
    LFUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};