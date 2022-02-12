Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root == NULL) return NULL;
   int val = root->data;
   if(n1<val && n2<val){
       return LCA(root->left, n1, n2);
   }
   else if(n1>val && n2>val){
       return LCA(root->right, n1, n2);
   }
   else return root;
}