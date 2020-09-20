
// 1. 排序的算法
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        // 排序, 将数组从小排到大
		// std::less<int>() 构造了一个临时对象, 这种类, 我们称之为仿函数, 因为less类中重载了()
		// 在sort源代码中当成函数使用
		// 如果想要从小到大排序, 那么就使用 std::greater<int>() 作为第三个参数. 默认也是这个. 但是我建议在写代码的时候
		// 显式的告诉别人, 这样代码更容易读懂
        sort(arr.begin(), arr.end(), std::less<int>());

        for (int i = 0; i < k ; ++i) {
            ans.push_back(arr[i]);
        }

        return ans;
		
		// 排序用了nlogn的时间复杂度, 而找出k个最小值用了 o(k)
		// 所以时间复杂度可以写成  nlogn + o(k), 也可以取他们中间的最大值
    }
};

// 采用优先队列 (heap来实现)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        // 用大根堆来实现  using namespae std
        // 在c++中大根堆就是priority_queue实现. 当然, 我们也可以用小根堆来实现
        // 首先将前k个元素放在pq中, 然后和剩下的元素进行比较

        // 可以简单的话就写成priority_queue<int> pq. 因为后面两个参数是默认的
        // 为了更好的理解, 我们就写全了
        // 第一个参数: 队列中元素的类型
        // 第二个参数: 队列是基于vector来实现的
        // 第三个参数: 大的元素在队列的顶部, less<int>是谓词函数类, 这样队列的头部就是最大值了
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0 ; i < k; ++i) {
            pq.push(arr[i]);
        }

        // 从第k个元素开始判断, 如果比堆顶小, 那么就将堆顶的元素pop掉, 然后将arr[i]替换进去
        for (int i = k ; i < arr.size(); ++i) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // 将队列中的元素都添加到返回值中
        for (int i = 0 ; i < k; ++i) {
             int temp = pq.top();
             pq.pop();
             ans.push_back(temp);
        }

        return ans;
    }
};