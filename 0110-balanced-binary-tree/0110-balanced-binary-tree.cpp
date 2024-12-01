/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left, right)+1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);

        int diff = abs(leftH-rightH);

        bool currNode = diff <= 1;

        bool leftNode = isBalanced(root->left);
        bool rightNode = isBalanced(root->right);

        return currNode && leftNode && rightNode;
    }
};