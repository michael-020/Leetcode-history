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
    void calculateSum(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> path, int sum){
        if(!root)
            return;

        sum += root->val;
        path.push_back(root->val);

        if(!root->left && !root->right){
            if(sum == target){
                ans.push_back(path);
                return;
            }
            else 
                return;
        }

        calculateSum(root->left, target, ans, path, sum);
        calculateSum(root->right, target, ans, path, sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        calculateSum(root, targetSum, ans, path, sum);

        return ans;
    }
};