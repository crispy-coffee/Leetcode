class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int l, int r, string& str){
        if(l == r)
            return 1;
        
        if(l > r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];

        int i = l+1;

        while(i<=r and str[i] == str[l])
            i++;
        
        if(i==r+1)
            return 1;
        
        int basic = 1 + solve(i, r, str);
    
        int lalach = INT_MAX;

        for(int j=i; j<=r; j++){
            if(str[l]==str[j]){
                int answer = solve(i, j-1, str) + solve(j, r, str);
                lalach = min(lalach, answer);
            }
        }

        return dp[l][r] = min(basic, lalach);
    }

    int strangePrinter(string s) {
        n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        
        return solve(0, n-1, s);
    }
};