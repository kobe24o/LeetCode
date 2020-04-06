class node{
public:
	int k, v, f;
	node(int key, int val, int freq):k(key),v(val),f(freq){}
};

class LFUCache {
	unordered_map<int, list<node>::iterator> kPos;//key 对应的节点迭代器位置
    unordered_map<int, list<node>> freq_list;//不同的频数下挂着一条双链表，尾部是最少使用的
    int cap;
    int minfreq;//最小的频数
    int size;
public:
    LFUCache(int capacity) {
    	cap = capacity;
    	minfreq = 0;
    	size = 0;
    }
    
    int get(int key) {
    	if(kPos.find(key)==kPos.end())
    		return -1;
    	auto it = kPos[key];//找到对应的迭代器
    	int f = it->f;
    	int v = it->v;
    	if(f == minfreq && freq_list[f].size() == 1)
    		minfreq++;//最小的频数的节点只有1个，被移走了，最小频数+1
    	freq_list[f].erase(it);//删除
    	freq_list[++f].push_front(node(key,v,f));//新频数链表加入新节点
    	kPos[key] = freq_list[f].begin();//记录迭代器位置
    	return v;
    }
    
    void put(int key, int value) {
    	if(kPos.find(key)!=kPos.end())
    	{	//存在key
    		auto it = kPos[key];
			int f = it->f;
			if(f == minfreq && freq_list[f].size()==1)
				minfreq++;
			freq_list[f].erase(it);
			freq_list[++f].push_front(node(key,value,f));
			kPos[key] = freq_list[f].begin();
    	}
    	else if(size < cap)//不存在key，但还可插入
    	{
			minfreq = 1;//新插入的只有1次
			freq_list[minfreq].push_front(node(key,value,1));
			kPos[key] = freq_list[1].begin();
			size++;
    	}
    	else if(cap != 0 && size == cap)//不存在key，且满了，且容量不为0
    	{
    		auto Node = freq_list[minfreq].back();
    		int k = Node.k;
    		freq_list[minfreq].pop_back();//频数最小的链表末尾的删除
    		kPos.erase(k);//删除末尾key对应的迭代器
    		size--;
    		put(key, value);
    	}
    }
};