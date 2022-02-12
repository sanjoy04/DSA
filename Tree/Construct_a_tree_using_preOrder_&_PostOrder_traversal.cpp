class Solution{
    public:
    int idx = 0;
    map<int,int>inMap;
    Node* buildingTree(int in[],int pre[],int start,int end){
        if(start > end){
            return NULL;
        }
        Node* root = new Node(pre[idx++]);
        if( start == end) return root;
        int inRoot = inMap[root->data];
        root->left = buildingTree(in, pre, start, inRoot-1);
        root->right = buildingTree(in, pre, inRoot+1, end);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i=0; i<n; i++){
            inMap[in[i]] = i;
        }
        Node* root = buildingTree(in,pre,0,n-1);
        return root;
        
    }
    
    
};