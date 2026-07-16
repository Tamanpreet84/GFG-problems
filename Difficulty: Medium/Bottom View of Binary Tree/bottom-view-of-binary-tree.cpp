/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> m;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            Node* f = q.front().first;
            int d = q.front().second;
            q.pop();

           
                m[d] = f->data;

            if (f->left)
                q.push({f->left, d - 1});

            if (f->right)
                q.push({f->right, d + 1});
        }

        for (auto x : m)
            ans.push_back(x.second);

        return ans;
    } 
};
