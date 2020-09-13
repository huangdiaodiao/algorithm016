# Queue
C++ STL Queue 的具体实现包含在std_queue.h文件中. 可以用浏览器访问<a href=https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01061_source.html>std_queue.h</a>.
## Queue的基本知识学习
 queue是一种FIFO数据结构, 在最底端移除元素, 在最顶端取出元素, 除此之外, 没有任何办法对元素进行存取. 也就是说, queue不允许有遍历行为.
 queue是基于别的container进行修改, 使其符合FIFO特性, 这种称之为adapter. 因此queue又被归类为container adapter.

## Queue源码学习
从源码可以分析出来, stl queue的底层容器(underlying container)是基于deque的.
```
template<typename _Tp, typename _Sequence = deque<_Tp> >
class queue {
    /* ... */
protected:
    _Sequence c;
}
```
关于push操作, 从源码可以看出, 在deque的尾部添加元素
```
void push(value_type&& __x) { 
    c.push_back(std::move(__x)); // std::move将__x转换为右值引用
}
```
关于pop操作, 在deque的头部将元素取出
```
void pop(){
__glibcxx_requires_nonempty();
   c.pop_front();
}
```
其他的接口函数, 不再一一进行分析. 值得注意的时候, FIFO不需要遍历, 因此queue不存在迭代器.

# priority_queue
priority_queue的实现源码也在std_queue.h中. 
## 基础知识学习
priority_queue是一个拥有权值观念的queue. 本质上是queue, 只不过元素拥有优先级的概念.

## 源码分析
```
template<typename _Tp, typename _Sequence = vector<_Tp>,
typename _Compare  = less<typename _Sequence::value_type> >
class priority_queue {
/*...*/
protected:
    _Sequence  c;
    _Compare   comp; // 权值比较函数
}
```
从上面源代码分析, 可以知道priority_queue是基于vector来实现的, 和queue不同的地方在于, 其提供了比较函数模板.
```
 priority_queue(const _Compare& __x = _Compare(),const _Sequence& __s = _Sequence()): c(__s), comp(__x) {
    std::make_heap(c.begin(), c.end(), comp); // 堆排序, 从大排到小
}
```
在构造的时候, 对元素就进行了排序. 
关于push操作, 可以看出, 每次添加一个元素都会进行一个堆排序
```
void push(const value_type& __x){
    c.push_back(__x);
    std::push_heap(c.begin(), c.end(), comp);
}
```
关于pop操作
```
void pop() {
    __glibcxx_requires_nonempty();
    std::pop_heap(c.begin(), c.end(), comp);// 假如是 3 2 1, 调用这个后, 变成 2 1 3
    c.pop_back(); // 然后将尾巴上的元素移除
}
```


## 参考资料
<STL源码剖析> 

www.cplusplus.com