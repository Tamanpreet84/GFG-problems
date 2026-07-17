/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
            int c = 0;
            unordered_set<int>s;
            void helper(Node* root){
                if(!root) return;
                
                s.insert(root->data);
                helper(root->left);
                helper(root->right);
                
            }
            
            void helper2(Node* root,int x){
                if (root == NULL)
            return;

        if (s.count(x - root->data))
            c++;

        helper2(root->left, x);
        helper2(root->right, x);
            }
            
    int countPairs(Node* root1, Node* root2, int x) {
        // code here
        helper(root1);
        helper2(root2, x);
        return c;
    }
};