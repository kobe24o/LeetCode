class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev = 0, maxtime = 0, time = 0;
        char ans = 'a';
        for(int i = 0; i < releaseTimes.size(); i++) 
        {
            time = releaseTimes[i]-prev;
            prev = releaseTimes[i];
            if(time > maxtime)
            {
                maxtime = time;
                ans = keysPressed[i];
            }
            else if(time == maxtime && keysPressed[i] > ans)
                ans = keysPressed[i];
        }
        return ans;
    }
};