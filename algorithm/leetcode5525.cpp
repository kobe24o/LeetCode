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