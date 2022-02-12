Node* checkRight(Node* root){
    if(root->right == NULL) return root;
    return checkRight(root->right);
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node *rightChild = root->right;
    Node* lastRight = checkRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    Node* dummy = root;
    if(root == NULL) return NULL;
    if(root->data == X){
        return helper(root);
    }
    while(root != NULL){
        if(root->data > X){
            if(root->left != NULL && root->left->data == X){
                root->left = helper(root->left);
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != NULL && root->right->data == X){
                root->right = helper(root->right);
            }
            else{
                root = root->right;
            }
        }
    }
    return dummy;
}