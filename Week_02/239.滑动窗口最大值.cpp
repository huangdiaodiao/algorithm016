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
