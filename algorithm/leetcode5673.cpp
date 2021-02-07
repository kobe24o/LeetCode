class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q; //大的优先
        q.push(a), q.push(b), q.push(c);
        int delta, ans = 0;
        while(1)
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            if(b == 0)
                break;
            c = q.top();
            delta = max(1, b-c);
            ans += delta;
            a -= delta;
            b -= delta;
            q.push(a);
            q.push(b);
        }
        return ans;
    }
};


class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        if(arr[0]+arr[1] <= arr[2])
            return arr[0]+arr[1];
        return (arr[0]+arr[1]+arr[2])/2;
    }
};
