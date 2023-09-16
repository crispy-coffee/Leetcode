class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(begin(v),end(v));
        vector<int> dp(n,0);
        int ans=v[0].second;
        dp[0] = v[0].second;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(v[j].second <= v[i].second){
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i] += v[i].second;
            ans = max(dp[i],ans);
        }
        // return *max_element(begin(dp),end(dp));
        return ans;
    }
};