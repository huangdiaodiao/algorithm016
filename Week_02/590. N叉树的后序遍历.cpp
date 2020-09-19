// 递归法
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        foo(root, ans);
        return ans;
    }

    void foo(Node* root, vector<int> &ans) {
        if (root == nullptr)
            return;
        for (auto &child: root->children) {
            foo(child, ans);
        }
        ans.push_back(root->val);
    }
};