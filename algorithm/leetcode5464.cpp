class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0, empty = 0;//喝的酒、空瓶子
        while(numBottles || empty >= numExchange)//有的喝，或还可以换
        {
            sum += numBottles;//喝掉
            empty += numBottles;//空瓶子多了
            numBottles = empty/numExchange;//能换几瓶酒
            empty -= numBottles*numExchange;//还剩几个空瓶子
        }
        return sum;
    }
};
