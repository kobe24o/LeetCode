class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),[&](auto a, auto b){
            return a[1] > b[1];//单元多的优先
        });
        int cell = 0;
        for(int i = 0; i < boxTypes.size(); ++i)
        {
            int num = min(truckSize, boxTypes[i][0]);//可以装的箱子数量
            cell += boxTypes[i][1]*num;
            truckSize -= num;//更新卡车剩余容量
        }
        return cell;
    }
};
