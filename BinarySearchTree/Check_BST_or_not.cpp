class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return isValid(root, INT_MIN, INT_MAX);
    }
    
    bool isValid(Node *root, int minVal, int maxVal){
        if(root == NULL) return true;
        if(root->data >= maxVal || root->data <= minVal) return false;
        return isValid(root->left, minVal, root->data) && isValid(root->right, root->data, maxVal);
    }
};