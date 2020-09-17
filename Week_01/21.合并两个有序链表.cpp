class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 递归的模型在之前的笔记里已经总结好了, 可以称之为内功, 这里, 通过这个题, 我们提炼出方法论
        // step1: 去理解一下这个函数做什么的, 自己在心中说出来: 输入两个有序链表, 将他们合并成一个有序链表然后输出出来
        // step2: 找到递推公式. 这里有个小技巧, 将函数名用f来替代. f(l1,l2) = l1 + f(l1->next,l2)   {如果l1->val<l2->val}
        //                                                                  = l2 + f(l1, l2->next)  {如果l1->val>=l2->val}
        // 从上面递推公式可以看出, 在进入递推栈之前, 是需要做一个判断的. 也就是我们递推模型中的, 入栈前操作
        // step3: 判断返回值. 返回的是合并后的链表
        // step4: 判断边界条件. 这里有坑, 最好画出来. 从这里可以看出, 如果l1为null, 那么返回l2, 因为l2可能还有一点元素,反之亦然

        // 边界条件
        if (l1 == nullptr)
            return l2;
         if (l2 == nullptr)
            return l1;

        // 入栈前判断一下
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};