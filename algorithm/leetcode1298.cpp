class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int sum = 0, id;
        unordered_set<int> nokeybox;
        for(int box : initialBoxes)
        {
            q.push(box);
        }
        while(!q.empty())
        {
            id = q.front();
            q.pop();
            sum += candies[id];
            for(int k : keys[id])
            {
                status[k] = 1;//这个盒子可以打开的
                if(nokeybox.count(k))
                {   //没有钥匙的盒子有钥匙了
                    q.push(k);//入队
                    nokeybox.erase(k);
                }
            }
            for(int box : containedBoxes[id])
            {
                if(status[box]==1)
                    q.push(box);
                else
                    nokeybox.insert(box);
            }
        }
        return sum;
    }
};