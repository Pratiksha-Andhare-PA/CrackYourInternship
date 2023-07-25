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
    int calDia(TreeNode* root, int &Height){
        if(root == NULL){
            Height = 0;
            return 0;
        }
        int lh=0, rh=0;
        int LD = calDia(root->left, lh);
        int RD = calDia(root->right, rh);

        int currD = lh+rh+1;
        Height = max(lh,rh) + 1;

        return max(currD, max(LD,RD));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int Height = 0;
        return calDia(root,Height)-1;
    }
};
