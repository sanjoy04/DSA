void findPath(Node* root, vector<vector<int>>&res, vector<int> &arr){
    if(root ==NULL) return;
    arr.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        res.push_back(arr);
        if(arr.size()>0) arr.pop_back();
        return;
    }
    
    findPath(root->left, res, arr);
    findPath(root->right, res, arr);
    
    if(arr.size()>0) arr.pop_back();
    return;
    
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> res;
    vector<int>arr;
    if(root==NULL) return res;
    findPath(root, res, arr);
    return res;
}