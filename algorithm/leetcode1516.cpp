/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    Node *pf = NULL, *qf = NULL;//父节点
    bool qisSubOfp = false;
    bool foundp = false;
    bool foundq = false;
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        for(auto node : q->children)
            if(node == p)//p是q的直接子节点，无需操作
                return root;
        Node* empty = new Node(-1);//建立空节点方便处理
        empty->children.push_back(root);
        dfs(empty, NULL, p, q);
        //q 不是 p 的子节点，p肯定不是root
        if(!qisSubOfp)
        {
            //找到 pf 子节点 p 的 iter
            auto it = find(pf->children.begin(),pf->children.end(),p);
            pf->children.erase(it);//删除之
            q->children.push_back(p);//p接到q的子节点中
            return root;
        }
        //q 是 p 的子树节点，p可能是root
        auto it = find(qf->children.begin(),qf->children.end(),q);
        qf->children.erase(it);//断开 q 与 qf
        it = find(pf->children.begin(),pf->children.end(),p);
        //断开 p 与 pf
        it = pf->children.erase(it);//it指向下一个，即 pf child 中 p 的下一个位置
        q->children.push_back(p);//接入到q下面
        pf->children.insert(it, q);//pf 的子节点 原来 p 的位置 插入 q
        return empty->children[0];
    }

    void dfs(Node* root, Node* fa, Node* p, Node* q)
    {
        if(!root) return;
        if(root == p)
        {
            pf = fa;
            foundp = true;
        }
        if(root == q)
        {
            if(foundp)
                qisSubOfp = true;
            qf = fa;
            foundq = true;
        }
        for(auto c : root->children)
            dfs(c, root, p, q);
        if(root == p)
            foundp = false;//回溯
        if(root == q)
            foundq = false;//回溯
    }   
};