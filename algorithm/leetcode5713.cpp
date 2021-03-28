class Solution {
public:
    int numDifferentIntegers(string word) {
        word.push_back('a');
        unordered_set<string> s;
        string num;
        for(auto c : word) {
            if(isalpha(c))
            {
                if(!num.empty())
                {
                    while(num.size()>1 && *num.begin()=='0')
                        num.erase(num.begin());
                    s.insert(num);
                    num = "";
                }
            }
            else//数字
            {
                num.push_back(c);
            }
        }
        return s.size();
    }
};