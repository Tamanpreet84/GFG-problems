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
    vector<int> topView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (mp.find(hd) == mp.end())
                mp[hd] = temp->data;

            if (temp->left)
                q.push({temp->left, hd - 1});

            if (temp->right)
                q.push({temp->right, hd + 1});
        }

        for (auto x : mp)
            ans.push_back(x.second);

        return ans;
    }
};