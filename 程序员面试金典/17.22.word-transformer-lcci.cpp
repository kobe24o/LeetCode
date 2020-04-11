class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> ans, frontPath, newpath;
        int len = wordList.size(), i, k, n, lv = 0;
        unordered_map<string,int> m;
        vector<bool> visited(len,false);
        for(i = 0; i < len; ++i)
        {
            m[wordList[i]] = i;
            if(wordList[i] == beginWord)
                visited[i] = true;
        }
        if(m.find(endWord) == m.end())
            return {};
        queue<vector<string>> q;
        frontPath.push_back(beginWord);
        q.push(frontPath);
        string str;
        while(!q.empty())
        {
            lv++;
            n = q.size();
            while(n--)
            {
                frontPath = q.front();
                q.pop();
                for(i = 0; i < beginWord.size(); ++i)
                {//对每个单词的每个字符进行改变
                    str = frontPath.back();
                    for(k = 1; k <= 25; ++k)
                    {
                        str[i] += 1;
                        if(str[i] > 'z')
                            str[i] = 'a';
                        if(m.find(str) != m.end() && !visited[m[str]])
                        {   //在集合中，且没有访问的
                            newpath = frontPath;
                            newpath.push_back(str);
                            q.push(newpath);
                            visited[m[str]] = true;
                            if(str == endWord)
                                return newpath;
                        }
                    }
                }
            }
        }
        return {};
    }
};