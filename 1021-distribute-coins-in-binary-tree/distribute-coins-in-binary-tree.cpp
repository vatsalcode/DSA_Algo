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
    int helper_balance(TreeNode* node, int& move){
        if(!node)return 0;
        int left=helper_balance(node->left,move);
        int right=helper_balance(node->right,move);

        int bal=node->val+left+right-1;
        move+=abs(left)+abs(right);
        return bal;
    }
    int distributeCoins(TreeNode* root) {
        int move=0;
        helper_balance(root,move);
        return move;
    }
};