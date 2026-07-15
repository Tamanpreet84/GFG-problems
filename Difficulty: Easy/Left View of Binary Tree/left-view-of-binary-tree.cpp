/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        
         queue<Node*> q;
         q.push(root);
         
         while(!q.empty()){
             int n = q.size();
             
             for(int i = 0; i < n; i++){
                 
                 Node* f =q.front();
                 q.pop();
                 if(i==0)ans.push_back(f->data);
                 if(f->left)q.push(f->left);

                if(f->right) q.push(f->right);
                 
                 
             }
             
         }
        return ans;
    }
};