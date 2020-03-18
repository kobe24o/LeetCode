class TripleInOne {
    int n, v;
    int size;
    vector<int> tail;//尾指针位置
    vector<int> stk;
public:
    TripleInOne(int stackSize) {
        n = stackSize;
        size = 3*stackSize;
        stk.resize(size);
        tail.resize(3);
        tail[0] = 0, tail[1] = stackSize, tail[2] = 2*stackSize;
    }
    
    void push(int stackNum, int value) {
        if(tail[stackNum] < (stackNum+1)*n )
        {
            stk[tail[stackNum]] = value;
            tail[stackNum]++;
        }
    }
    
    int pop(int stackNum) {
        if(tail[stackNum] == stackNum*n)
            return -1;
        v = stk[tail[stackNum]-1];
        tail[stackNum]--;
        return v;
    }
    
    int peek(int stackNum) {
        if(tail[stackNum] == stackNum*n)
            return -1;
        return stk[tail[stackNum]-1];
    }
    
    bool isEmpty(int stackNum) {
        return tail[stackNum]==stackNum*n;
    }
};