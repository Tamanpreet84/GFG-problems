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
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        int min_level = 0;
        int max_level = 0;
        
        while(!q.empty()){
            
            Node* Current = q.front().first;
            int axes = q.front().second;
            q.pop();
            
            min_level = min(min_level,axes);
            max_level = max(max_level,axes);
            
            if(Current->left!=NULL){
                q.push({Current->left,axes-1});
            }
            
            if(Current->right!=NULL){
                q.push({Current->right,axes+1});   
            }
            
            if(mp.find(axes)==mp.end()){
                mp[axes]=Current->data;
            }
        }
        
        vector<int> ans;
        for(int i=min_level;i<=max_level;i++){
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};