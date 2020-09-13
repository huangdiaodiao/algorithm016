// 暴力求解法
class Solution {
public:
    int trap(vector<int>& height) {
        // 暴力求解法
        // 找到当前元素的左边和右边的最大值. 假设为 leftmax\rightmax
        // 那么当前元素可以承接: ans = min(leftmax-cur, rightmax-cur)单位的水.

        int ans = 0;
        int size = height.size();

        for (int i = 1; i < size - 1; ++i) {
            int leftmax = 0;
            int rightmax = 0;
            for (int j = i; j >=0; --j) {
                leftmax = std::max(leftmax, height[j]);
            }
            for (int j = i; j < size ; ++j) {
                rightmax = std::max(rightmax, height[j]);
            }

            ans += std::min(rightmax, leftmax) - height[i];
        }

        return ans; 
    }

    // 时间复杂度为O(n^2)
    // 空间复杂度为O(1)
};



// 使用栈

class Solution {
public:
    // 通过栈来解决
    int trap(vector<int>& height) {
        
        int ans = 0;
        int size = height.size();
        std::stack<int> st; // 保存数组的坐标值

        for (int i = 0; i < size; ++i) {
            // 如果当前元素比栈顶指向的元素高, 那么就对当前元素和之前元素围起来的面积进行计算
            while (!st.empty() && height[i] > height[st.top()]) {
                int lower = height[st.top()];
                st.pop();
                if (st.empty()) break;
                int w = i - st.top() - 1;
                int curH = height[i];
                int leftH = height[st.top()];
                int h = std::min(curH, leftH) - lower;

                ans = ans + (w * h);
            } 
            st.push(i);
            
        }
        return ans; 
    }

    // 时间复杂度为O(n)
    // 空间复杂度为O(1)
};
