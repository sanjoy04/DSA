class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* current = root;
        while(root){
            if(current->val <= val){
                if(current->right != NULL) current = current->right;
                else{
                    current->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(current->left != NULL) current = current->left;
                else{
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};