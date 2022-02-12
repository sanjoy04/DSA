//Iterative solution
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int ele;
            while(size--){
                Node* node = q.front();
                q.pop();
                ele = node->data;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(ele);
        }
        return res;
    }
};

//Recursive solution
class Solution
{
    private:
    void recursive(Node* root, vector<int> &ans, int level){
        if(root == NULL) return;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        recursive(root->right, ans, level+1);
        recursive(root->left, ans, level+1);
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        recursive(root, ans, 0);
        return ans;
    }
};