class node{
public:
	int k, v, f;
	node(int key, int val, int freq):k(key),v(val),f(freq){}
};

class LFUCache {
	unordered_map<int, list<node>::iterator> kPos;//key 对应的节点迭代器位置
    unordered_map<int, list<node>> freq_list;//不同的频数下挂着一条双链表，尾部是最少使用的
    int cap;
    int minfreq;
    int size;
public:
    LFUCache(int capacity) {
    	cap = capacity;
    	minfreq = 0;
    	size = 0;
    }
    
    int get(int key) {
    	if(!kPos.count(key))
    		return -1;
    	auto it = kPos[key];
    	int f = it->f;
    	int v = it->v;
    	if(f == minfreq && freq_list[f].size() == 1)
    		minfreq++;
    	freq_list[f].erase(it);
    	freq_list[++f].push_front(node(key,v,f));
    	kPos[key] = freq_list[f].begin();
    	return v;
    }
    
    void put(int key, int value) {
    	if(kPos.count(key))
    	{
    		auto it = kPos[key];
			int f = it->f;
			if(f == minfreq && freq_list[f].size()==1)
				minfreq++;
			freq_list[f].erase(it);
			freq_list[++f].push_front(node(key,value,f))
			kPos[key] = m[f].begin();
    	}
    	else if(size < cap)
    	{
			minfreq = 1;
			m[minfreq].push_front(node(key,value,1));
			kPos[key] = m[1].begin();
			size++;
    	}
    	else
    	{
    		auto Node = freq_list[minfreq].back();
    		int k = Node.k;
    		freq_list[minfreq].pop_back();
    		kPos.rease(k);
    		size--;
    		put(key, value);
    	}
    }
};