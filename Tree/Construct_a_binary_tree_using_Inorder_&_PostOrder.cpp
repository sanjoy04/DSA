map<int, int> inMap;
Node* buildingTree(int in[], int inStart, int inEnd,
                    int post[], int posStart, int posEnd){
    if(inStart > inEnd || posStart > posEnd){
        return NULL;
    }
    Node* root = new Node(post[posEnd]);
    int inRoot = inMap[root->data];
    int inLeft = inRoot - inStart;
    root->left = buildingTree(in,inStart,inRoot-1,post,posStart,posStart+inLeft-1);
    root->right = buildingTree(in,inRoot+1,inEnd,post, posStart+inLeft,posEnd-1);
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    
    for(int i=0; i<n; i++) inMap[in[i]] = i;
    Node* root = buildingTree(in,0,n-1,post,0,n-1);
    return root;
}