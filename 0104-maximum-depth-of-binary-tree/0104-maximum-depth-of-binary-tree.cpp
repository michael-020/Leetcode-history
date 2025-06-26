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
    int calcDiameter(TreeNode* root){
        if(!root)
            return 0;

        int left = calcDiameter(root->left);
        int right = calcDiameter(root->right);

        return max(left, right)+1;
    }

    int maxDepth(TreeNode* root) {
        return calcDiameter(root);
    }
};