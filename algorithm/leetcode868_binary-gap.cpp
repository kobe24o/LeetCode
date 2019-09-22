class Solution {
public:
    int binaryGap(int N) {
        int indexOfOne[32] = {0}, idx = 0;
        for (int i = 0; i < 32; ++i)
        {
        	if((N & (1<<i)) != 0)
        		indexOfOne[idx++] = i;
        }
        int maxGap = 0, curGap, prevOneIndex;
        for (int i = 0; i < 31; ++i)
        {
        	curGap = indexOfOne[i+1]-indexOfOne[i];
        	if(maxGap < curGap)
        		maxGap = curGap;
        }
        return maxGap;
    }
};