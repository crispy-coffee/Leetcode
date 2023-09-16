class Solution {
public:
    int effort = INT_MAX;
    void dfs(int i, int j, int prev, int sum, vector<vector<int>>& heights){
        if(i<0 or i>=heights.size() or j<0 or j>=heights[0].size() or heights[i][j]<0){
            return;
        }

        sum = max(abs(heights[i][j] - prev), sum);
        
        if(i==heights.size()-1 and j==heights[0].size()-1){
            effort = min(effort, sum);
            return;
        }

        prev = heights[i][j];
        heights[i][j] = -100;
        dfs(i+1, j, prev, sum, heights);
        dfs(i-1, j, prev, sum, heights);
        dfs(i, j+1, prev, sum, heights);
        dfs(i, j-1, prev, sum, heights);
        heights[i][j] = prev;
    }

    typedef pair<int,pair<int,int>> P;
    int DijkstraAlgo(vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> path(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        path[0][0] = 0;
        pq.push({0, {0, 0}});

        auto isSafe = [&](int x, int y){
            return x>=0 and x<n and y>=0 and y<m;
        };
        vector<pair<int,int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            
            int oldDiff = pq.top().first;
            auto location = pq.top().second;

            pq.pop();
            int x = location.first;
            int y = location.second;

            for(auto& dir:direction){

                int x_ = x+dir.first;
                int y_ = y+dir.second;
                if(isSafe(x_, y_)){ 

                    int currDiff = abs(heights[x][y] - heights[x_][y_]);
                    int newDiff = max(currDiff, oldDiff);
                    
                    if(path[x_][y_] > newDiff){
                        path[x_][y_] = newDiff;
                        pq.push({newDiff, {x_, y_}});
                    }
                }
            }

        }

        return path[n-1][m-1];

    }

    int minimumEffortPath(vector<vector<int>>& heights) {        
        // TLE
        // dfs(0, 0, heights[0][0], 0, heights); 
        // return effort;
        
        return DijkstraAlgo(heights);

    }
};
