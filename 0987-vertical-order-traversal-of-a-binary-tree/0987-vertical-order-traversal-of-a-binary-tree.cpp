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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(node->val);

        
            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto &col : nodes){
            vector<int> v;
            for(auto &row : col.second){
                v.insert(v.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(v);
        }

        return ans;
    }
};