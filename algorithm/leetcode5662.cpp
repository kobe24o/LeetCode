class Solution {
public:
    int minCharacters(string a, string b) {
        int n1[26] = {0}, n2[26] = {0};
        int n[26] = {0};
        char maxa='a', mina='z', maxb = 'a', minb = 'z';
        for(auto c : a)
        {
            n1[c-'a']++;
            n[c-'a']++;
            maxa = max(maxa, c);
            mina = min(mina, c);
        }
        for(auto c : b)
        {
            n2[c-'a']++;
            n[c-'a']++;
            maxb = max(maxb, c);
            minb = min(minb, c);
        }
        // 自然满足条件
        if(minb > maxa || mina > maxb) return 0;
        int maxchar = 0;//所有字符最多的
        for(int i= 0; i < 26; i++)
            maxchar = max(maxchar, n[i]);
        int ans = a.size()+b.size()-maxchar;//两人都变成这个字符
        // 以下是比赛时写错的代码，最后一个例子过不了
        // ---------------------
        // "a"
        // "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
        // --------------------------------------
        // int numa = 0, numb = 0;
        // for(int i = 0; i < 26; i++)
        // {
        //     numa += n1[i];
        //     numb += n2[i];
        //     ans = min(ans, int(a.size())-numa+numb);
        //     ans = min(ans, int(b.size())-numb+numa);
        // }
        // 要改的话，就是把 26 改成 25，a [i+1,25] 的字符改到前面，+ b [0, i] 的改到后面
        // i+1 < 26 , i < 25
        int numa = n1[0], numb = n2[0]; 
        for(int i = 1; i < 26; i++)
        {
            // a [i,25] 的字符改到前面，+ b [0, i-1] 的改到后面
            ans = min(ans, int(a.size())-numa+numb);
            // b [i,25] 的字符改到前面，+ a [0, i-1] 的改到后面
            ans = min(ans, int(b.size())-numb+numa);
            numa += n1[i];
            numb += n2[i];
        }
        return ans;
    }
};