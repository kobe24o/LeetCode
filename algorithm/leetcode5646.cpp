class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int p = languages.size(); // 人数
        unordered_map<int, unordered_set<int>> lang_peoples;//语言 - 会的人集合
        for(int i = 0; i < p; i++) 
        {
            for(auto l : languages[i])
                lang_peoples[l].insert(i);
        }
        vector<bool> canspeak(friendships.size(), false);//能沟通吗
        for(int i = 0; i < friendships.size(); i++)
        {
            int a = friendships[i][0]-1, b = friendships[i][1]-1;
            for(auto& lp : lang_peoples)
            {
                if(lp.second.count(a) && lp.second.count(b))
                {
                    canspeak[i] = true;
                    break;
                }
            }
        }
        // 这里比赛的时候写成了 n-1, 我哭了，我就说逻辑没错啊。。。
        int teach = p-1, count = 0; //至少要教 p-1个人
        for(auto& lp : lang_peoples)
        {	// 遍历语言
            count = 0;
            for(int i = 0; i < friendships.size(); i++)
            {	// 遍历关系
                int a = friendships[i][0]-1, b = friendships[i][1]-1;
                if(canspeak[i])//能沟通的忽略
                    continue;
                if(!lp.second.count(a))
                {	//不能沟通，且不会这种语言，学习
                    lp.second.insert(a);
                    count++;
                }
                if(!lp.second.count(b))
                {	//不能沟通，且不会这种语言，学习
                    lp.second.insert(b);
                    count++;
                }
            }
            teach = min(teach, count);
        }
        return teach;
    }
};


or

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int p = languages.size(); // 人数
        unordered_map<int, unordered_set<int>> lang_peoples;//语言 - 会的人集合
        for(int i = 0; i < p; i++) 
        {
            for(auto l : languages[i])
                lang_peoples[l].insert(i);
        }
        vector<bool> canspeak(friendships.size(), false);//能沟通吗
        for(int i = 0; i < friendships.size(); i++)
        {
            int a = friendships[i][0]-1, b = friendships[i][1]-1;
            for(auto& lp : lang_peoples)
            {
                if(lp.second.count(a) && lp.second.count(b))
                {
                    canspeak[i] = true;
                    break;
                }
            }
        }
        vector<int> lang_people_can_say(n,0);
        unordered_set<int> pp;//不能沟通的人们
        for(int i = 0; i < friendships.size(); i++)
        {	// 遍历关系
            if(canspeak[i])//能沟通的忽略
                continue;
            int a = friendships[i][0]-1, b = friendships[i][1]-1;
            if(!pp.count(a))
            {
                pp.insert(a);
                for(auto l : languages[a])
            	    lang_people_can_say[l-1]++;
                    //统计不能沟通的人会说的语言
            }
            if(!pp.count(b))
            {
                pp.insert(b);
                for(auto l : languages[b])
            	    lang_people_can_say[l-1]++;
                    //统计不能沟通的人会说的语言
            }
        }
        return pp.size() - *max_element(lang_people_can_say.begin(),
        								lang_people_can_say.end());
    }
};
