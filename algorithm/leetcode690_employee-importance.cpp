/*
// Employee info
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
	unordered_map<int,Employee*> m;//id,其地址的映射关系
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        for(auto Ep : employees)
        	m[Ep->id] = Ep;
        dfs(m[id],sum);
        return sum;
    }

    void dfs(Employee* p, int &sum)
    {
    	sum += p->importance;
    	for(int id : p->subordinates)
    		dfs(m[id],sum);
    }
};

class Solution {
	unordered_map<int,Employee*> m;//id,其地址的映射关系
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        for(auto Ep : employees)
        	m[Ep->id] = Ep;
        
        //BFS
        queue<int> q;
        q.push(id);
        while(!q.empty())
        {
        	sum += m[q.front()]->importance;
        	for(int &id : m[q.front()]->subordinates)
        		q.push(id);
        	q.pop();
        }
        return sum;
    }
};