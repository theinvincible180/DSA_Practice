class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void bfs(queue<pair<int, int>>& qt, int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int& cnt){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        while(!qt.empty()){
            auto it = qt.front();
            qt.pop();

            int row = it.first;
            int col = it.second;

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    cnt++;
                    qt.push({nrow, ncol});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> qt;

        int mxCnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int cnt = 1;
                    qt.push({i, j});
                    bfs(qt, i, j, vis, grid, cnt);
                    mxCnt = max(cnt, mxCnt);
                }
            }
        }

        return mxCnt;
    }
};
