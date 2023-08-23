class Solution
{
public:
    int row, col;
    vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty())
        {
            auto land = q.front();
            q.pop();
            int r = land.first;
            int c = land.second;
            for (auto dir : direction)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr < row && nr >= 0 && nc < col && nc >= 0 && grid[nr][nc] == '1' &&
                 visited[nr][nc] == false)
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }

  /*void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        visited[i][j] = true;
        grid[i][j] = '0'
        for(auto dir: direction){
            int nr = i+dir.first;
            int nc = j+dir.second;
            if(nr >=0 and nr<row and nc>=0 and nc<col and grid[nr][nc] == '1' and visited[nr][nc] == false){
                dfs(nr, nc, grid, visited);
            }
        }
    }
    */
    void dfs(int i, int j, vector<vector<char>> &grid){
        grid[i][j] = '0';
        for(auto dir: direction){
            int nr = i+dir.first;
            int nc = j+dir.second;
            if(nr >=0 and nr<row and nc>=0 and nc<col and grid[nr][nc] == '1'){
                dfs(nr, nc, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        col = grid[0].size();

        if (row == 0 || col == 0)
            return 0;

        // vector<vector<bool>> visited(row, vector<bool>(col, false));
        int island = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    // bfs(i, j, grid, visited);
                    dfs(i, j, grid);
                    island++;
                }
            }
        }

        return island;
    }
};