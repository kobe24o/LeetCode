/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<vector<NestedInteger>::iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        vector<NestedInteger>::iterator tp;
        while(!begins.empty())
        {
            if(begins.top()==ends.top())
            {
                begins.pop();
                ends.pop();
            }
            else
            {
                tp = begins.top();
                if(tp->isInteger())
                    return true;
                //不是整数,是个列表
                begins.top()++;//当前的移到下一个
                //处理tp这个列表，压栈
                begins.push(tp->getList().begin());
                ends.push(tp->getList().end());;
            }
        }
        return false;
    }
};