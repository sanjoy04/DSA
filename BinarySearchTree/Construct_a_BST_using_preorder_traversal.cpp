class Solution {
public:
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder, INT_MAX);
    }
    
    TreeNode* constructBST(vector<int>& preorder, int limit){
        if(i== preorder.size() || preorder[i] > limit) return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = constructBST(preorder, root->val);
        root->right = constructBST(preorder, limit);
        return root;
    }
};