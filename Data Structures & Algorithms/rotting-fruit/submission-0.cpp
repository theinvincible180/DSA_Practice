class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    int bfs(queue<pair<int, pair<int, int>>>& qt, vector<vector<int>>& grid, int& cnt, vector<vector<int>>& dist){
        int n = grid.size();
        int m = grid[0].size();

        while(!qt.empty()) {
            auto it = qt.front();
            qt.pop();

            int dis = it.first;

            cnt = max(cnt, dis);

            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1  && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1;
                    grid[nrow][ncol] = 2;
                    qt.push({dist[nrow][ncol], {nrow, ncol}});
                } 
            }

        }

        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> qt;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2) {
                    dist[i][j] = 0;
                    qt.push({0, {i, j}});
                }
            }
        }

        int cnt = 0;
        bfs(qt, grid, cnt, dist);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return cnt;
    }
};
