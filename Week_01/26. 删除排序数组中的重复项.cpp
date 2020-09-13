// 快慢指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return size;

        int s = 0;
        for (int f = 0;f < size - 1; ++f) {
            if (nums[f] != nums[f+1]) {
                nums[s+1] = nums[f+1];
                ++s;
            }
        }

        return ++s;
    }

    // 时间复杂度为O(n)
    // 空间复杂度为O(1)
};