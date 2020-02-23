class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int count[10] = {0}, i, sum = 0, time;
        string ans; 
        for(i = 0; i < digits.size(); ++i)
        {
            count[digits[i]]++;
            sum += digits[i];
            ans += digits[i]+'0';
        }
        sort(ans.begin(), ans.end(),[](char& a, char& b){return a > b;});
        if(sum%3 == 1)
        {
            i = ans.size()-1;
            if(count[1]!=0||count[4]!=0||count[7]!=0)
            {
                for( ; i>=0; --i)
                {
                    if(ans[i]=='1'||ans[i]=='4'||ans[i]=='7')
                    {
                        ans.erase(ans.begin()+i);
                        break;
                    }
                }
            }
            else
            {   
                time = 2;
                for( ; i>=0; --i)
                {
                    if(ans[i]=='2'||ans[i]=='5'||ans[i]=='8')
                    {
                        ans.erase(ans.begin()+i);
                        time--;
                        if(time == 0)
                            break;
                    }
                }
            }
        }
        else if(sum%3 == 2)
        {
            i = ans.size()-1;
            if(count[2]!=0||count[5]!=0||count[8]!=0)
            {
                for( ; i>=0; --i)
                {
                    if(ans[i]=='2'||ans[i]=='5'||ans[i]=='8')
                    {
                        ans.erase(ans.begin()+i);
                        break;
                    }
                }
            }
            else
            {   
                time = 2;
                for( ; i>=0; --i)
                {
                    if(ans[i]=='1'||ans[i]=='4'||ans[i]=='7')
                    {
                        ans.erase(ans.begin()+i);
                        time--;
                        if(time == 0)
                            break;
                    }
                }
            }
        }
        if(ans != "" && ans[0]=='0')
            return "0";
        return ans;
    }
};