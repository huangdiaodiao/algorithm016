class MyCircularDeque {
public:
     // 解题目思路:
     // queue是一个FIFO结构
     // deque可以用list来进行模拟

     // 声明每个元素的结构
     struct Node {
         int val;
         Node *pre;
         Node *next;
         Node():val(-1), pre(NULL), next(NULL){}
     };

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        mOpacity = k;
        mSize = 0;
        // 初始化头节点和尾节点
        mHead = new Node;
        mTail = new Node;
        mHead->next = mTail;
        mTail->pre  = mHead;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        // 判断一下
        if (isFull()) return false; 

        // 先构造新节点, 然后调整指针指向
        Node *node =  new Node;
		node->val = value;
		node->pre = mHead;
		node->next = mHead->next;
		node->next->pre = node;
		node->pre->next = node;
        
        // 记录元素个数
        ++mSize;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        // 判断一下
        if (isFull()) return false; 

        // 先构造新节点, 然后调整指针指向
        Node *node =  new Node;
		node->val = value;
		node->pre = mTail->pre;
		node->next = mTail;
		mTail->pre->next = node;
		mTail->pre = node;

        // 记录元素个数
        ++mSize;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        Node *front = mHead->next; // 暂存
        mHead->next->next->pre = mHead;
        mHead->next = mHead->next->next;
        delete front;
        front = NULL;
        --mSize;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        //if (isEmpty()) return false;
        //Node *last = mTail->pre;
        //last->next->pre = last->pre;
        //last->pre->next = last->next;
		//delete last;
        //last = NULL;
        //--mSize;
        //return true;
		
		if (isEmpty()) return false;
		auto node = mTail->pre;
		node->next->pre = node->pre;
		node->pre->next = node->next;
		delete node;
		node = NULL;
		--mSize;
		return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return mHead->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return mTail->pre->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return mSize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return mSize == mOpacity;
    }

private:
    int mOpacity; // Dequeue预留的大小
    int mSize; // 当前大小
    Node *mHead;
    Node *mTail;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */