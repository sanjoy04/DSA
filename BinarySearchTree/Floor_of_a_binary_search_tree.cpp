int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor = -1;
    while(root){
        if(root->val == X){
            floor = root->val;
            return floor;
        }
        if(root->val > X){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}