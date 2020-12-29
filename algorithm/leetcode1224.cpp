class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> m;//数字，数字的个数freq
        map<int,int> size_count;//数字的个数freq，freq的频数
        int maxlen = 1, MINf, MAXf;
        for(int i = 0; i < nums.size(); ++i) 
        {
            m[nums[i]]++;
            size_count[m[nums[i]]]++;
            if(--size_count[m[nums[i]]-1] <= 0)
                size_count.erase(m[nums[i]]-1);
            MINf = size_count.begin()->first;
            MAXf = size_count.rbegin()->first;
            // 1, [1,2,3,4,5] size_count[1] = 5
            // 2, [2,2,2,2] size_count[4] = 1
            // 3, [2,2,1,1,0,0,3,3,3] size_count[2] = 3, size_count[3] = 1
            // 4, [1,2,2,2,3,3,3] size_count[1] = 1, size_count[3] = 2
            // 这4种情况才可以
            if((size_count.size()==1 && (MINf==1 || size_count[MINf]==1))||(size_count.size()==2 && ((size_count[MAXf]==1 && MAXf-MINf==1) || (size_count[MINf]==1 && MINf==1))))
                maxlen = i+1;
        }
        return maxlen;
    }
};