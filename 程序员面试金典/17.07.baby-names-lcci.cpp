class Solution {
    unordered_map<string,string> father;//并查集
    unordered_map<string,int> m;//名称，频次
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        string name, name1, name2, p;
        int i, count;
        for(string& n : names)
        {
            i = n.find("(");
            name = n.substr(0,i);
            count = 0;
            while(++i < n.size()-1)
                count = 10*count+n[i]-'0';
            m[name] = count;//获取每个名字的次数
            father[name] = name;//并查集初始化
        }
        for(auto& n : synonyms)
        {   //这里可能有上面不存在的name，再添加一遍
            i = n.find(",");
            name1 = n.substr(1,i-1);
            name2 = n.substr(i+1,n.size()-i-2);
            father[name1] = name1;//并查集初始化
            father[name2] = name2;//并查集初始化
        }
        for(auto& n : synonyms)
        {
            i = n.find(",");
            name1 = n.substr(1,i-1);
            name2 = n.substr(i+1,n.size()-i-2);
            merge(name1,name2);//全部进行合并和路径压缩
        }
        unordered_map<string,vector<string>> fatherSet;
        for(auto f : father)//压缩后的f(只有两层)，所有边的顶层（字典序最小的）
        {
            name = f.first;
            p = uniFind(name);
            fatherSet[p].push_back(name);
        }
        vector<string> ans;
        for(auto& f : fatherSet)
        {	//所有的等效名字
            count = 0;
            for(auto& v : f.second)//它底下包含的name
                count += m[v];//加上他的计数
            ans.push_back(f.first+"("+to_string(count)+")");
        }
        return ans;
    }

    string uniFind(string x)
    {
        if(x == father[x])
            return x;
        return father[x] = uniFind(father[x]);//等式为路径压缩操作
    }

    void merge(string x, string y)
    {
        string fatherx = uniFind(x);
        string fathery = uniFind(y);
        if(fatherx != fathery)
        {
            if(fatherx < fathery)
                swap(fatherx, fathery);//x的字典序大
            father[fatherx] = fathery;//字典序小的y做代表
        }
    }
};