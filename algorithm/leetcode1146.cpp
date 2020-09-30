class SnapshotArray {
    int time = 0;
    unordered_map<int,map<int,int>> m;//idx, time, val
public:
    SnapshotArray(int length) { }
    
    void set(int index, int val) {
        m[index][time] = val;
    }
    
    int snap() {
        return time++;
    }
    
    int get(int index, int snap_id) {
        if(!m.count(index))
            return 0;
        auto it = m[index].upper_bound(snap_id);
        if(it == m[index].begin())
            return 0;
        return (--it)->second;
    }
};