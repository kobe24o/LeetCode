class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        if(array.size() < 2)
            return {};
        unordered_map<int, int> m;
        int start = 0, end = 0, sum = 0;
        for(int i = 0; i < array.size(); ++i)
        {
            if(isdigit(array[i][0]))
                sum++;
            else
                sum--;
            if(sum == 0)//等于0，表示[0,i]满足题意
                start = 0, end = i; 
            else if(!m.count(sum))//其他数字，记录起点
                m[sum] = i; 
            else if(i-m[sum] > end-start+1)//map包含sum，长度更大
            {
                start = m[sum]+1;//更新区间端点
                end = i;
            }
        }
        if(start == end)
            return{};
        return vector<string>(array.begin()+start, array.begin()+end+1);
    }
};