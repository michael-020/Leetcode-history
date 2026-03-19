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
    int findDiameter(TreeNode* root){
        if(!root)
            return 0;

        int left = findDiameter(root->left);
        int right = findDiameter(root->right);

        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = findDiameter(root->left)+findDiameter(root->right);

        return max(op1, max(op2, op3));
    }
};