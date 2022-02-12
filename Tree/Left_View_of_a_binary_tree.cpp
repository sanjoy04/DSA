//Iterative solution
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>res;
    if(root==NULL) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        res.push_back(q.front()->data);
        while(size--){
            Node* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return res;
}


//Recursive solution
void recursive(Node* root, vector<int> &ans, int level){
    if(root == NULL) return;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    recursive(root->left, ans, level+1);
    recursive(root->right, ans, level+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    recursive(root, ans, 0);
    return ans;
}