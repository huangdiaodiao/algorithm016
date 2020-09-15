class Solution {
public:
    bool isAnagram(string s, string t) {
        /* 暴力法, 将两个字符串先排序, 然后再比较是否相等 */
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 时间复杂度为NlogN


//
//  总结: 使用hash表来存储数据, 和用stack来存储数据都是充分利用了数据结构的特点来解决问题
//        因此, 在解决一些问题的时候, 应该先分析问题, 然后再去找合适的数据结构, 有事半功倍的效果
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        /* 使用哈希表来解决 */

        unordered_map<char, int> hashmap;

        for (auto &ch : s) {
            ++hashmap[ch];
        }

        for (auto &ch : t) {
            if (hashmap.count(ch) > 0) {
                --hashmap[ch];
            } else {
                return false;
            }
        }

        return true;
        
        // 时间复杂度 O(n)
        // 空间复杂度 O(n)
    }
};