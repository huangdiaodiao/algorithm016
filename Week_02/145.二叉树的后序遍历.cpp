// 递归写法几乎形成了机械记忆
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        // 使用递归  左 右 根
        vector<int> ans;
        postoder(root, ans);
        return ans;
    }

    void postoder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        
        postoder(root->left, ans);
        postoder(root->right, ans);
        ans.push_back(root->val);
    }
};

// 第二种解法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        // 使用栈来进行后序遍历. 后序遍历是左右根, 在实际操作中是很不好处理的. 因此我们, 改进一下前序
        // 采用根右左, 然后最后结果reverse一下即可
        stack<TreeNode *> st;
        vector<int> ans;

        while(root || !st.empty()) {
            
            while(root) {
                ans.push_back(root->val); // 根
                st.push(root);
                root = root->right; //右 
            }

            root = st.top()->left; // 左
            st.pop();
        }

        // 最后的结果反转
        reverse(ans.begin(), ans.end());
        return ans;
    }
};