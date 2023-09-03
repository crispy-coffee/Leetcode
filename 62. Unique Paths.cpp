class Solution {
public:
    int Recursion(int i, int j, int m, int n){
        if(i>=m or j>=n)
            return 0;
        
        if(i==m-1 and j==n-1)
            return 1;
        
        int first = Recursion(i+1, j, m, n);
        int second = Recursion(i, j+1, m, n);

        return first + second;

    }

    int Memoizatoin(int i, int j, int m, int n, vector<vector<int>>& dp){
         if(i>=m or j>=n)
            return 0;
        
        if(i==m-1 and j==n-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int first = Memoizatoin(i+1, j, m, n, dp);
        int second = Memoizatoin(i, j+1, m, n, dp);

        return dp[i][j] = first + second;
    }
    int uniquePaths(int m, int n) {
        // 1 Recursion
        // return Recursion(0, 0, m, n);

        // 2 Recursion With Memoization
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return Memoizatoin(0, 0, m, n, dp);


    }
};