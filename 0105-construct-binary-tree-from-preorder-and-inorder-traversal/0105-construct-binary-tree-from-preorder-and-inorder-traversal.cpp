class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int mid = pos[rootValue];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};