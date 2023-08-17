
class Solution {
public:
    int n;
    int m;

    int DFS(int i, int j, vector<vector<int>>& mat, vector<vector<bool>>& visited){
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j]){
            return INT_MAX-10;
        }

        if(mat[i][j] == 0){
            return 0;
        }

        visited[i][j] = true;
        long left = DFS(i, j-1, mat, visited);
        long right = DFS(i, j+1, mat, visited);
        long up = DFS(i-1, j, mat, visited);
        long down = DFS(i+1, j, mat, visited);
        visited[i][j] = false;

        return min({left, right, up, down})+1;

    }

    vector<vector<int>> bruteforce(vector<vector<int>>& mat){
        vector<vector<int>> result(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j])
                    result[i][j] = DFS(i, j, mat, visited);
            }
        }

        return result;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        // return bruteforce(mat);

        return BFS(mat);
    }

    vector<vector<int>> BFS(vector<vector<int>>& mat){
        vector<vector<int>> result(n,vector<int>(m, -1));
        vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;

            for(auto dir:direction){
                int new_i = i + dir.first;
                int new_j = j + dir.second;

                if(new_i >= 0 and new_i < n and new_j >= 0 and new_j < m and result[new_i][new_j] == -1){
                    result[new_i][new_j] = result[i][j] + 1;

                    q.push({new_i, new_j});
                }
            }
        }

        return result;
    }
};