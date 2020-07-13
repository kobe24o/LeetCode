class FreqStack {
	unordered_map<int,int> freq;//num,freq
	unordered_map<int, stack<int>> stk;//freq，栈，一个数有这个频数时，存入
	int maxfreq = 0;//最大频数
	int x;
public:
    FreqStack() {

    }
    
    void push(int x) {
    	freq[x]++;
    	maxfreq = max(maxfreq, freq[x]);
    	stk[freq[x]].push(x);
    }
    
    int pop() {
    	x = stk[maxfreq].top();
        freq[x]--;
    	stk[maxfreq].pop();
    	if(stk[maxfreq].empty())
    		maxfreq--;
    	return x;
    }
};