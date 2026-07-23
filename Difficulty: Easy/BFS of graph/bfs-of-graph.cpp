class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        vector<bool>vi(adj.size());
        queue<int> q;

        q.push(0);
        vi[0] = 1;

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for (auto n : adj[f]) {
                if (!vi[n]) {
                    vi[n] = 1;
                    q.push(n);
                }
            }
        }

        return ans;
    }
};