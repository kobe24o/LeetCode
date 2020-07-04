class PhoneDirectory {
    unordered_set<int> unused, used;
    int tel;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; ++i)
            unused.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(unused.empty()) return -1;
        tel = *unused.begin();
        unused.erase(*unused.begin());
        used.insert(tel);
        return tel;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return unused.find(number) != unused.end();//没有用过
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
        unused.insert(number);
    }
};