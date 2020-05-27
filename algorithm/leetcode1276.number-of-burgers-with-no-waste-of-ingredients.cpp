class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int a = tomatoSlices - 2*cheeseSlices;
        if(a < 0 || (a&1)) return {};
        int juwuba = a/2;
        int xiaohuangbao = cheeseSlices - juwuba;
        if(xiaohuangbao >= 0)
            return {juwuba, xiaohuangbao};
        return {};
    }
};