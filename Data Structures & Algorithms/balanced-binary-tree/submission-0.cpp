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
    int findHleft(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(findHleft(root->left), findHleft(root->right));
    }
    int findHright(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(findHright(root->left), findHright(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root== nullptr) return true;

        int lh = findHleft(root->left);
        int rh = findHright(root->right);

        if(abs(rh-lh)>1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};
