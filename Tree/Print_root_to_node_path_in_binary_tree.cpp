vector<int> solve(Node *root, int B){
    vector<int>ans;
    if(root == NULL) return ans;
    findPath(root, ans, B);
    return ans;
}

bool findPath(Node* root, vector<int> &ans, int B){
    if(root ==NULL) return false;
    ans.push_back(root->data);
    if(root->data == B) return true;
    if(findPath(root->left,ans,B) || findPath(root->right,ans,B))
        return true;
    ans.pop_back();
    return false;

}