class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b)
            swap(a, b);
        if(a > c)
        	swap(a, c);
        if(b > c)
        	swap(b, c);
        if(b-a == 1 && c-b == 1)
        	return {0, c-a-2};
        if((b-a == 1 && c-b != 1) || (b-a != 1 && c-b == 1) || (b-a == 2) || (c-b) == 2)
        	return {1, c-a-2};
        return {2, c-a-2};
    }
};