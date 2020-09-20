// 暴力法 -- 超出时间限制
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for (int i = 0; i <= nums.size() - k; ++i) {
            int maxValue = INT_MIN;
            for (int j = i; j < i + k; ++j) {
                maxValue = max(nums[j], maxValue);
            }
            ans.push_back(maxValue);
        }

        return ans;
    }
};

// 用堆来完成
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> que;
        for (int j = 0; j < nums.size(); ++j) {
            que.push({nums[j], j});
            if (j >= k - 1) {
                // (j-k+1)是窗口第一个元素的左边, 如果队列中的最大元素超过了这个范围, 那么就要将最大值弹出去
                while (que.top().second < j - k + 1)
                    que.pop();
                ans.push_back(que.top().first);
            }
        }
        return ans;
    }
};

