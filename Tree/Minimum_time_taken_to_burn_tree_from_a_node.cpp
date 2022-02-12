class Solution {
  public:
    int findTimeToBurn(map<Node*, Node*> &parent, Node* target){
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(target);
        visited[target] = true;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            int fl=0;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    fl = 1;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    fl = 1;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]]){
                    fl = 1;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(fl==1) count++;
        }
        return count;
    }
  
    Node* findParentAndTarget(Node* root, map<Node*, Node*> &parentTrack, int target){
        queue<Node*> q;
        q.push(root);
        Node* ele;
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target) ele = node;
            q.pop();
            if(node->left){
                parentTrack[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentTrack[node->right] = node;
                q.push(node->right);
            }
        }
        return ele;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*>parentTrack;
        Node* element = findParentAndTarget(root, parentTrack, target);
        int ans = findTimeToBurn(parentTrack, element);
        return ans;
    }
};