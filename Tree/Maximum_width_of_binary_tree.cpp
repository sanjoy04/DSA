class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        // Following code is for total number of possible nodes
        
        // if(!root)
        //     return 0;
        // int ans = 0;
        // queue<pair<Node*, int>> q;
        // q.push({root,0});
        // while(!q.empty()){
        //     int size = q.size();
        //     int mmin = q.front().second;
        //     int first,last;
        //     for(int i=0; i<size; i++){
        //         int cur_id = q.front().second-mmin;
        //         Node* node = q.front().first;
        //         q.pop();
        //         if(i==0) first = cur_id;
        //         if(i==size-1) last = cur_id;
        //         if(node->left)
        //             q.push({node->left, cur_id*2+1});
        //         if(node->right)
        //             q.push({node->right, cur_id*2+2});
        //     }
        //     ans = max(ans, last-first+1);
        // }
        // return ans;
        
        // Following code is for total number nodes present
        
        if (root == NULL)
        return 0;
        int result = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            result = max(count, result);
            while (count--) {
                Node* temp = q.front();
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
     
        return result;
    }
};