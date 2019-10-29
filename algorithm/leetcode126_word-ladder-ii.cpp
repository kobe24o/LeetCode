#include <unordered_set>
#include <string>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        unordered_set<string> wlist(wordList.begin(),wordList.end());
        unordered_set<string> words;//存放当次被加入到路径的单词
        queue<vector<string>> q;//队列里存放的是可行的路径
        q.push({beginWord});
        words.insert(beginWord);
        int level = 1, minLevel = INT_MAX, n, i;
        vector<string> frontPath, newPath;
        string lastWordOfPath, newLastWord;
        char ch;
        while(!q.empty())
        {
            n = q.size();
            while(n--)
            {
                frontPath = q.front();//vector<string>
                q.pop();//frontPath出队
                if(frontPath.size() > level)//下一个level时进入
                {
                    for(string word:words) 
                        wlist.erase(word);//将上一个lv进入路径的单词从集合中删除
                    words.clear();
                    level = frontPath.size();//level+1
                    if(level > minLevel) //如果level比最小的还大，没必要进行下去
                        break;
                }
                lastWordOfPath = frontPath.back();
                for(i = 0; i < lastWordOfPath.size(); i++)
                {   //根据最后一个单词衍生新的单词
                    newLastWord = lastWordOfPath;
                    for(ch = 'a'; ch <= 'z'; ch++)
                    {
                        newLastWord[i] = ch;
                        if(!wlist.count(newLastWord)) //新单词不在集合中,下一个
                            continue;
                        words.insert(newLastWord);//在集合中，加入路径，并记录在words
                        newPath = frontPath;//vector<string>
                        newPath.push_back(newLastWord);
                        if(newLastWord == endWord)
                        {
                            ans.push_back(newPath);
                            minLevel = level;
                        }
                        else
                            q.push(newPath);
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit","cog",v);
}