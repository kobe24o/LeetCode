class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area), L = area/W;
        while(W*L != area)
        {
        	W--;
        	L = area/W;
        }
        return{L,W};
    }
};