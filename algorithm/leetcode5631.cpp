class Solution {    // 贪心，错误解
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0], maxNegative = INT_MIN, idx = -1;
        for(int i = 1; i < n; ++i) 
        {
            int step = k;
            bool inNegativePos = true;
            bool reachEnd = false;
            maxNegative = INT_MIN;
            for( ; i < n && step--; i++)
            {
                if(nums[i] >= 0)
                {
                    ans += nums[i];
                    inNegativePos = false;
                    break;
                }
                else
                {
                    if(i == n-1)
                        reachEnd = true;
                    if(nums[i] >= maxNegative)
                    {
                        maxNegative = nums[i];
                        idx = i;
                    }
                }
            }
            if(inNegativePos)
            {
                if(reachEnd)
                {
                    ans += nums[n-1];
                    break;
                }
                else
                {
                    ans += nums[idx];
                    i = idx;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        priority_queue<pair<int,int>> q;// sum. idx
        q.push({nums[0], 0});
        for(int i = 1; i < n; ++i) 
        {
            while(i-q.top().second > k)//这些位置，不能跳到 i 位置
                q.pop();
            //能调过来的位置，选最大的，跳到 i
            ans = q.top().first + nums[i];// 到 i位置的最优选择
            q.push({ans, i});//存入优先队列
        }
        return ans;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        deque<pair<int,int>> q;// sum. idx
        q.push_back({nums[0], 0});
        for(int i = 1; i < n; ++i) 
        {
            while(i-q.front().second > k)//这些位置，不能跳到 i 位置
                q.pop_front();
            //能调过来的位置，选最大的，跳到 i

            ans = q.front().first + nums[i];// 到 i位置的最优选择
            while(!q.empty() && q.back().first <= ans)
                q.pop_back();
            q.push_back({ans, i});//存入队列
        }
        return ans;
    }
};