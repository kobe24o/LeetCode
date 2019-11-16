/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* q1, Node* q2) {
        if(q1->isLeaf || q2->isLeaf)//至少有一个时叶子(全0 or 全1)
        {
            if(q1->isLeaf && q2->isLeaf)
            {
                bool v = q1->val || q2->val;
                return new Node(v,true,0,0,0,0);
            }
            else if(q1->isLeaf)
            {
                if(q1->val == false)
                    return q2;
                else
                    return q1;
            }
            else//q2->isLeaf
            {
                if(q2->val == false)
                    return q1;
                else
                    return q2;
            }
        }
        
        else//q1,q2都不是叶子，其下面有true，有false
        {
            Node *root = new Node(false,false,0,0,0,0);
            root->topLeft = intersect(q1->topLeft, q2->topLeft);
            root->topRight = intersect(q1->topRight, q2->topRight);
            root->bottomLeft = intersect(q1->bottomLeft, q2->bottomLeft);
            root->bottomRight = intersect(q1->bottomRight, q2->bottomRight);
            if(root->topLeft->isLeaf && root->topRight->isLeaf
                        && root->bottomLeft->isLeaf && root->bottomRight->isLeaf)
            {   //都是叶子
                bool topL = root->topLeft->val;
                if(root->topRight->val == topL && root->bottomLeft->val == topL
                        && root->bottomRight->val == topL)
                {   //且值都相同
                    root->isLeaf = true;
                    root->val = topL;
                    //舍弃孩子(合并了)
                    root->topLeft = root->topRight = root->bottomLeft
                        = root->bottomRight = NULL;
                }
            }
            return root;
        }
    }
};