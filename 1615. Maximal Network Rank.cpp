class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxi = INT_MIN;
        vector<vector<bool>> connect(n, vector<bool>(n,false));
        vector<int> indegree(n,0);

        for(auto i:roads){
            connect[i[0]][i[1]] = true;
            connect[i[1]][i[0]] = true;

            indegree[i[0]]++;
            indegree[i[1]]++;
        }

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int size = indegree[i] + indegree[j] - connect[i][j];
                maxi = max(maxi, size);
            }
        }

        return maxi;
    }
};