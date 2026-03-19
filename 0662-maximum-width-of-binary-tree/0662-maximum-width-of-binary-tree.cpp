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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        int maxWidth = 0;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                long long curr_id = p.second-mini;

                if(i == 0) first = curr_id;
                if(i == size-1) last = curr_id;

                if(node->left)
                    q.push({node->left, curr_id*2+1});
                if(node->right)
                    q.push({node->right, curr_id*2+2});
            }

            maxWidth = max(maxWidth, last-first+1);
        }

        return maxWidth;
    }
};