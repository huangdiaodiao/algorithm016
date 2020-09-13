class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
    // 时间复杂度 为 O(n)
    // 空间复杂度 为 O(1)
};