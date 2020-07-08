class FirstUnique {
	unordered_map<int,int> map;
	queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
    	for(int n : nums)
    	{
    		q.push(n);
    		map[n]++;
    	}
    }
    
    int showFirstUnique() {
    	while(!q.empty() && map[q.front()] >1)
    		q.pop();
    	if(q.empty()) return -1;
    	return q.front();
    }
    
    void add(int value) {
    	q.push(value);
    	map[value]++;
    }
};