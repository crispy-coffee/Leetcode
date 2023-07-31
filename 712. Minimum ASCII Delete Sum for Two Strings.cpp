class Solution {
public:
    int value(string& s, int i){
        int sum = 0;
        for(; i<s.size(); i++){
            sum += (int)s[i];
        }
        return sum;
    }

    int Recursion(string& s1, string& s2, int i, int j){
        if(i == s1.size()) 
            return value(s2, j);
        
        if(j == s2.size())
            return value(s1, i);
        
        if(s1[i] == s2[j])
            return Recursion(s1, s2, i+1, j+1);
        else
            return min((int)s1[i] + Recursion(s1, s2, i+1, j), (int)s2[j] + Recursion(s1, s2, i, j+1));

    }

    int Memoization(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == s1.size()) 
            return value(s2, j);
        
        if(j == s2.size())
            return value(s1, i);
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = Memoization(s1, s2, i+1, j+1, dp);
        else
            return dp[i][j] = min((int)s1[i] + Memoization(s1, s2, i+1, j, dp), (int)s2[j] + Memoization(s1, s2, i, j+1, dp));

    }

    int minimumDeleteSum(string s1, string s2) {
        // 1 Recursion
        // return Recursion(s1, s2, 0, 0);

        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return Memoization(s1, s2, 0, 0, dp);
    }
};