class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string,map<string,int>> m;//桌号，菜，数量
        vector<vector<string>> food = {{"Table"}};
        vector<string> tableId;
        for(auto& od : orders)
        {
        	m[od[1]][od[2]]++;
        	tableId.push_back(od[1]);
        	food[0].push_back(od[2]);
        }
        sort(tableId.begin(), tableId.end(),[&](auto a, auto b){
            if(a.size()==b.size())
                return a < b;
            return a.size() < b.size();
        });
        tableId.erase(unique(tableId.begin(),tableId.end()), tableId.end());
        sort(food[0].begin()+1, food[0].end());
        food[0].erase(unique(food[0].begin()+1, food[0].end()), food[0].end());
        food.resize(tableId.size()+1);
        for(int i = 1; i < food.size(); ++i)
        {
        	food[i].push_back(tableId[i-1]);
        	for(int j = 1; j < food[0].size(); ++j)
        		food[i].push_back(to_string(m[food[i][0]][food[0][j]]));
        }
        return food;
    }
};