class Solution {
public:
    int n, m;
    vector<pair<int,int>> direction = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool safe(int i, int j){
        return !(i<0 or i>=n or j<0 or j>=m);
    }

    int Recursion(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int path=0;
        for(auto dir:direction){
            int x = i+dir.first;
            int y = j+dir.second;
            if(safe(x, y) and matrix[i][j]<matrix[x][y]){
                path = max(path, 1+Recursion(x, y, matrix, dp));
            }
        }
        return dp[i][j] = path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(), m=matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                count = max(count, 1+Recursion(i, j, matrix, dp));
            }
        }
        return count;
    }
};