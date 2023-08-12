class Solution {
public:

    int Recursion(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i==n or j==m or grid[i][j] == 1)
            return 0;
        
        if(i == n-1 and j == m-1    )
            return 1;
        
        
        int right = Recursion(i+1, j, n, m, grid);
        int down = Recursion(i, j+1, n, m, grid);

        return right + down;
    }

    int Memoization(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==n or j==m or grid[i][j] == 1)
            return 0;
        
        if(i == n-1 and j == m-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = Memoization(i+1, j, n, m, grid, dp);
        int down = Memoization(i, j+1, n, m, grid, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // return Recursion(0, 0, n, m, obstacleGrid);

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Memoization(0, 0, n, m, obstacleGrid, dp);

    }
};