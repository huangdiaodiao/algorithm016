// 二叉树为什么适用于递归呢?
// 因为二叉树天然拥有类似的子问题
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 中序遍历   左  根  右
        vector<int> ans;
        inorder(root, ans); 
        return ans;
    }

    void inorder(TreeNode* root, vector<int> &ans) {
        if (root == nullptr)
            return;
         
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};

// 用栈的方法来模拟递归过程
// 从某种程度上来说, 递归就是通过函数调用栈来自动维护, 而这里我们可以手动维护一个栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty()) {

            for(;root != nullptr; root = root->left) {
                st.push(root); // 左
            }
            
            root = st.top();
            st.pop();
            ans.push_back(root->val); // 根
            root = root->right; // 右
        }
        return ans;
    }
};