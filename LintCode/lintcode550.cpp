unordered_map<string, int> wc;
struct cmp {
    bool operator()(const string &a,const string &b) 
    {   //必须写const，不写报错
        if (wc[a] == wc[b])
            return a < b;
        return wc[a] > wc[b];
    }
};

class TopK {
private:
    set<string,cmp> q;
    int K;
public:
    TopK(int k) { K = k;}

    void add(string word) {
        if (q.find(word) != q.end())//必须用find，不能用count
            q.erase(word);
        wc[word]++;
        q.insert(word);
        if (q.size() > K)
            q.erase(--q.end());
    }

    vector<string> topk() {
        return vector<string> (q.begin(), q.end());
    }
};