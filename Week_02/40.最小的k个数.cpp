
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
    }
};