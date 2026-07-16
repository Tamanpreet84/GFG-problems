/* structure of binary tree node
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
        int mx = INT_MIN;
  
    int helper(Node* root) {
        
        // code here
        
        
        if(root==NULL)
        return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int sum = l+r+root->data;
        
        mx=max(mx,sum);
        
        return sum;
    } 
        int maxSubtreeSum(Node* root){
            helper (root);
            
            return mx;
        
    }
};
