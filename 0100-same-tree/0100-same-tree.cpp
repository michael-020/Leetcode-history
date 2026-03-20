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
    void postOrder(TreeNode* root, vector<int> &v){
        if(!root){
            v.push_back(INT_MIN);
            return;
        }

        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->val);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        vector<int> postOrderP;
        vector<int> postOrderQ;

        postOrder(p, postOrderP);
        postOrder(q, postOrderQ);

        if(postOrderP.size() != postOrderQ.size())
            return false;

        for(int i=0; i<postOrderP.size(); i++){
            if(postOrderP[i] != postOrderQ[i])
                return false;
        }

        return true;
    }
};