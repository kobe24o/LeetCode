class ThroneInheritance {
    unordered_map<string, vector<string>> g;
    unordered_set<string> passaway;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        g[kingName];
    }
    
    void birth(string parentName, string childName) {
        g[parentName].push_back(childName);//建图
    }
    
    void death(string name) {
        passaway.insert(name);//记录去世的
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(king, ans);//深度优先搜索
        return ans;
    }
    void dfs(string& people, vector<string>& ans)
    {
        if(passaway.find(people) == passaway.end())
            ans.push_back(people);//继承人存活
        for(auto& child : g[people])
            dfs(child, ans);
    }
};
//----------------------
//
class people
{
public:
    bool dead = false;
    list<people*> children;
    string name;
    people(string &name)
    {
        this->name = name;
    }
};

class ThroneInheritance {
    unordered_map<people*, string> m;
    unordered_map<string, people*> m1;
    string king;
    vector<string> ans;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        people* root = new people(kingName);
        m[root] = king;
        m1[king] = root;
    }
    
    void birth(string parentName, string childName) {
        people* newchild = new people(childName);
        m[newchild] = childName;
        m1[childName] = newchild;
        m1[parentName]->children.emplace_back(newchild);
    }
    
    void death(string name) {
        m1[name]->dead = true;
    }
    
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(m1[king]);
        return ans;
    }
    void dfs(people* p)
    {
        if(p->dead == false)
            ans.push_back(m[p]);
        for(auto child : p->children)
            dfs(child);
    }
};