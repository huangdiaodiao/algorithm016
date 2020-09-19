// 循环 + 栈的实现方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        // 采用循环+栈的办法来处理
        // 因为这是前序遍历, 根 左 右, 因此我们要先将右孩子放入栈中间
        vector<int> ans;
        stack<TreeNode *> st;
        
        while (root != nullptr || !st.empty()) {

            for (;root != nullptr;) {
                ans.push_back(root->val); // 先将根结点放在结果中
                st.push(root->right); // 再将右孩子放入栈中间
                root = root->left; // 递归到左孩子
            }

            // 走到这里是树的左孩子已经到头了
            // 将栈顶的右孩子弹出来, 处理右孩子
            root = st.top();
            st.pop();
        }

        return ans;
    }
};