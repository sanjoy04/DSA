void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
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
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParent(root,parentTrack,target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level=0;
        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parentTrack[node] && !visited[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }



    //Solution when the value of terget node is given
    class Solution
{
private:
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

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*, Node*>parentTrack;
        Node* element = findParentAndTarget(root, parentTrack, target);
        queue<Node*>q;
        map<Node*, bool> vis;
        q.push(element);
        vis[element] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parentTrack[node] && !vis[parentTrack[node]]){
                    vis[parentTrack[node]] = true;
                    q.push(parentTrack[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->data);
            q.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};