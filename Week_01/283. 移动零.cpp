class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZero = 0;
        int i = 0;
        while(i < nums.size()) {
            // 解决子问题
            if (nums[i] != 0 )
                swap(nums[firstZero++], nums[i]);
            ++i;
        } 
    }
};

// 时间复杂度O(n)
// 空间复杂度O(1)