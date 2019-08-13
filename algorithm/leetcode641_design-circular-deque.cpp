/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/14 0:23
 * @modified by: 
 */
class MyCircularDeque {
    int capa;
    int curSize;
    int frontP, backP;
    int *dq;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capa = k;
        curSize = 0;
        dq = new int [capa];
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(isEmpty())
        {
            frontP = backP = 0;
        }
        else
        {
            frontP--;
            if(frontP == -1)
                frontP = capa-1;
        }
        dq[frontP] = value;
        curSize++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        if(isEmpty())
        {
            frontP = backP = 0;
        }
        else
        {
            backP++;
            if(backP == capa)
                backP = 0;
        }
        dq[backP] = value;
        curSize++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        frontP++;
        if(frontP == capa)
            frontP = 0;
        curSize--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        backP--;
        if(backP == -1)
            backP = capa-1;
        curSize--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        return dq[frontP];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        return dq[backP];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return curSize == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return curSize == capa;
    }
};