/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        // code here
        if (root == NULL)
            return INT_MIN;
            
            int l = findMax(root->left);
            int r = findMax(root->right);
            
            return max(root->data,max(l,r));
        
    }

    int findMin(Node *root) {
        
        // code here
        if (root == NULL)
            return INT_MAX;
            
            int l = findMin(root->left);
            int r = findMin(root->right);
            
            return min(root->data,min(l,r));
    }
};