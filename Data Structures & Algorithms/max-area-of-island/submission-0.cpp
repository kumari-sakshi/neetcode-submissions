
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int n = grid.size();
        int m = grid[0].size();

        vis[x][y] = 1;
        int cnt = 1;  // count current cell

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m &&
                grid[x1][y1] == 1 && !vis[x1][y1]) {
                cnt += dfs(x1, y1, grid, vis);
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxm = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int val = dfs(i, j, grid, vis);
                    maxm = max(maxm, val);
                }
            }
        }

        return maxm;
    }
};






