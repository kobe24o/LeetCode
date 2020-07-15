class node
{
public:
    int val;
    unordered_set<string> s;
    node(int v)
    {
        val = v;
    }
};
class AllOne {
    unordered_map<string, list<node>::iterator> m;
    list<node> l;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = m.find(key);
        if(it == m.end())
        {
            if(l.empty() || l.front().val > 1)
                l.push_front(node(1));
            l.begin()->s.insert(key);
            m[key] = l.begin();
        }
        else
        {
            auto iter = it->second;
            int num = iter->val;
            iter->s.erase(key);
            auto olditer = iter;
            auto newiter = ++iter;

            num++;
            if(newiter != l.end() && newiter->val == num)
            {
                newiter->s.insert(key);
                m[key] = newiter;
            }
            else
            {
                auto temp = l.insert(newiter,node(num));
                temp->s.insert(key);
                m[key] = temp;
            }
            if(olditer->s.empty())
                l.erase(olditer);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = m.find(key);
        if(it == m.end()) return;
        auto iter = it->second;
        int num = iter->val;
        iter->s.erase(key);
        auto olditer = iter;
        auto newiter = --iter;

        num--;
        if(num == 0)
            m.erase(key);
        else if(olditer != l.begin() && newiter->val == num)
        {
            newiter->s.insert(key);
            m[key] = newiter;
        }
        else
        {
            auto temp = l.insert(olditer,node(num));
            temp->s.insert(key);
            m[key] = temp;
        }
        if(olditer->s.empty())
            l.erase(olditer);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(l.empty()) return "";
        return *(l.back().s.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(l.empty()) return "";
            return *(l.front().s.begin());
    }
};