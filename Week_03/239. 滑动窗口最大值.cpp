class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }
    
    int max() { return data.front(); }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) { 
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};


/*
做该题的感想
刚开始, 只能想到暴力解法. 但是隐约知道应该有一个"高级的数据结构"来解决这个问题. 
想到了优先队列等. 百思不得其解. 后来看了别人的解答后.才知道自己陷入了一个思维的误区.

错误的思维误区 : 更高效的解法 --> priority_queue? deque? 还是什么高级数据结构呢 --> 陷入死胡头

正确的思维逻辑 : 更高效的解法 --> 抽象一个数据结构 --> 应该要有哪些特点 --> 寻找合适数据结构

我们先假设这个抽象数据结构叫 mydata, 它应该有一下几个特点
1. 最大值很好取
2. 很方便的弹出和插入

根据这个数据结构特点, 很自然的想到deque. 当然, 现在对各个数据结构还不是很熟悉. 多多做题, 就熟悉了各种数据结构解决什么特点的问题有用的. 

但是, 一定要刻意训练自己的正确的思维逻辑. 
*/
