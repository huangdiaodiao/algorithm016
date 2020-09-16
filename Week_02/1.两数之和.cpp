class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 采用hashmap来做

        int size = nums.size();
        // 首先将数组存到hashmap中, 下标作为value. 因为题目说了, 不会有两个答案, 那么也不会有相同的元素
        unordered_map<int, int> hashmap;
        for (int i = 0; i < size; ++i) 
            hashmap[nums[i]] = i;
        
        // 遍历数组
        for (int i = 0; i < size; ++i) {
            if (hashmap.count(target - nums[i]) > 0 ) {
                return {i, hashmap[target - nums[i]]};
            }
        }

        return {};    
    }
};