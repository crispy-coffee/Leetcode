class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> rotten;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    rotten.push({i, j});
                }
            }
        }

        int timer = 0;
        vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!rotten.empty()){
            
            int size = rotten.size();

            bool fresh = false;
            for(int s=0; s<size; s++){
                auto kharab = rotten.front();   
                rotten.pop();
                int i = kharab.first;
                int j = kharab.second;

                for(auto dir:direction){
                    int _i = i+dir.first;
                    int _j = j+dir.second;
                    if(_i >=0 and _i<n and _j>=0 and _j<m and grid[_i][_j] == 1){
                        grid[_i][_j] = 2;
                        fresh = true;
                        rotten.push({_i, _j});
                    }
                }
            }

            if(fresh)
                timer++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return timer;
    }
};