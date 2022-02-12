class Solution
{
    public:
    void inOrder(Node *root, vector<int> &v){
        if(root){
            inOrder(root->left,v);
            v.push_back(root->data);
            inOrder(root->right,v);
        }
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v;
        inOrder(root,v);
        int n = v.size();
        if(K>n) return -1;
        else return v[n-K];
    }
};