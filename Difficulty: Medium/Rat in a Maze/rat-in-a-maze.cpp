class Solution {
public:
    vector<string> ans;

    void travel(vector<vector<int>>& maze, int n, int i, int j, string psf) {
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
            return;

        if (i == n - 1 && j == n - 1) {
            ans.push_back(psf);
            return;
        }

        maze[i][j] = 0;

        travel(maze, n, i + 1, j, psf + "D");
        travel(maze, n, i, j - 1, psf + "L");
        travel(maze, n, i, j + 1, psf + "R");
        travel(maze, n, i - 1, j, psf + "U");

        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();

        if (maze[0][0] == 0)
            return {};

        travel(maze, n, 0, 0, "");

        return ans;
    }
};