/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int> ans;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
            
            ans.push_back(f->data);
        }
        
            return ans;
        
        
    }
};