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
    void inorder(TreeNode* root, vector<pair<int, int>>& v, const int &index){
        if(!root){
            v.push_back({0, -1});
            return;
        }

        inorder(root->left, v, 2*index+1);

        v.push_back({root->val, index});

        inorder(root->right, v, 2*index+2);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        vector<pair<int, int>> inorderP;
        vector<pair<int, int>> inorderQ;
        const int index = 0, id = 0;
        inorder(p, inorderP, index);
        inorder(q, inorderQ, id);

        if(inorderP.size() != inorderQ.size())
            return false;

        for(int i=0; i<inorderP.size(); i++){
            if(inorderP[i].first != inorderQ[i].first || inorderP[i].second != inorderQ[i].second)
                return false;
        }

        return true;
    }
};