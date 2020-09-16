class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string , vector<string>> hashmap;

        for (auto &str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(str);
        }

        for (unordered_map<string , vector<string>>::iterator iter = hashmap.begin();
            iter != hashmap.end(); ++iter) {
                ans.push_back(iter->second);
            }

        return ans;
    }
};