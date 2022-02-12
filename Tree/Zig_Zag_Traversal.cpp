class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> res;
    	queue<Node*>q;
    	int flag = 0;
    	q.push(root);
    	while(!q.empty()){
    	    vector<int> level;
    	    int size = q.size();
    	    for(int i=0; i<size; i++){
        	    Node *node = q.front();
        	    q.pop();
        	    if(node->left != NULL) q.push(node->left);
        	    if(node->right != NULL) q.push(node->right);
        	    level.push_back(node->data);
    	    }
    	    if(flag==0){
    	        for(int i=0; i<level.size(); i++){
    	            res.push_back(level[i]);
    	        }
    	        flag = 1;
    	    }
    	    else if(flag==1){
    	        reverse(level.begin(), level.end());
    	        for(int i=0; i<level.size(); i++){
    	            res.push_back(level[i]);
    	        }
    	        flag = 0;  
    	    }
    	}
    	return res;
    }
};


//Or we can do this
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> res;
    	queue<Node*>q;
    	int flag = 0;
    	q.push(root);
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> level(size);
    	    for(int i=0; i<size; i++){
        	    Node *node = q.front();
        	    q.pop();
        	    int index = (flag==0)? i:(size-1-i);
        	    if(node->left != NULL) q.push(node->left);
        	    if(node->right != NULL) q.push(node->right);
        	    level[index] = node->data;
    	    }
    	    for(int i=0; i<level.size(); i++){
    	            res.push_back(level[i]);
    	        }
    	    flag = 1-flag;
    	}
    	return res;
    }
};