class Solution {//bitmap solution
public:
    int findDuplicate(vector<int>& nums) {
        int idx, bit;
        int numOfBytes = (nums.size()-1)/8+1;
        char bytes[numOfBytes];
        memset(bytes,0,numOfBytes*sizeof(char));
        for(int i = 0; i < nums.size(); ++i)
        {
            idx = nums[i]/8, bit = nums[i]%8;
            if(!(bytes[idx]&(1<<bit)))
                bytes[idx] |= (1<<bit);
            else
                return nums[i];
        }
        return -1;
    }
};

class Solution {//set solution
public:
    int findDuplicate(vector<int>& nums) {
        
    }
};