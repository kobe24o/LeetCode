/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
map<string, int> wc;

struct cmp {
    bool operator()(string &a, string &b) {
        if (wc[a] == wc[b])
            return a < b;
        return wc[a] > wc[b];
    }
};

class TopK {
private:
    set<string,cmp> q;
    int K;
public:
    /*
    * @param k: An integer
    */TopK(int k) {
        // do intialization if necessary
        K = k;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string word) {
        // write your code here
        if (q.count(word))
            q.erase(word);
        wc[word]++;
        q.insert(word);
        if (q.size() > K)
            q.erase(--q.end());
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        // write your code here
        return vector<string>(q.begin(), q.end());
    }
};

int main() {
//    Solution s;
    TopK t(2);
    t.add("lint");
    t.add("code");
    t.add("code");
    t.topk();

    vector<string> v = {"a", "b"};
    string str = "eceeeefasdghjklqwertyuio";
//    s.lengthOfLongestSubstringKDistinct(str,3);
    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    return 0;
}