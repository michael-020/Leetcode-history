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

        return max(left, right)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int left = isBalanced(root->left);
        int right = isBalanced(root->right);
        int ans = abs(maxDepth(root->left)-maxDepth(root->right));
        if(ans > 1 || !left || !right)
            return false;

        return true;
    }
};