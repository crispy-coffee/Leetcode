class Solution {
public:
    int solve(vector<vector<int>>& pairs,int i,int j,vector<vector<int>>& dp)
    {
        if(j == pairs.size())        
            return 0;

        if(dp[i+1][j] != -1)
            return dp[i+1][j];
        
        int include=0;

        if(i == -1 || pairs[i][1] < pairs[j][0])
        {
            include = 1 + solve(pairs,j,j+1,dp);
        }

        int exclude = solve(pairs,i,j+1,dp);

        return dp[i+1][j] = max(include,exclude);
    }

    int Tabulation(vector<vector<int>>& pairs){
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int i=n-2; i>=-1; i--){
            for(int j=n-1; j>=0; j--){
                
                int include=0;

                if(i == -1 || pairs[i][1] < pairs[j][0])
                {
                    include = 1 + dp[j+1][j+1];
                }

                int exclude = dp[i+1][j+1];

                dp[i+1][j] = max(include,exclude);
            }
        }

        return dp[0][0];

    }

    int greedy(vector<vector<int>>& pairs){
        sort(begin(pairs), end(pairs), [&](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int answer = 0;
        int left = -1001;
        for(auto i:pairs){
            if(left < i[0]){
                answer++;
                left = i[1];
            }
        }
        return answer;
    }

    int findLongestChain(vector<vector<int>>& pairs) 
    {   
        /*
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(pairs,-1,0,dp);
        */

        // return Tabulation(pairs);

        return greedy(pairs);
    }
};