//Using extra space
class Solution {
  public:
    void inOrder(Node *root, vector<int> &v){
        if(root){
            inOrder(root->left, v);
            v.push_back(root->data);
            inOrder(root->right,v);
        }
    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        vector<int> v;
        inOrder(root,v);
        if(K>v.size()) return -1;
        else return v[K-1];
    }
};