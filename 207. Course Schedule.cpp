class Solution {
public:
    bool dfs(int parent, vector<bool>& visited, unordered_map<int, vector<int>>& adj){

        if(visited[parent])
            return false;
        
        visited[parent] = true;
        for(int child:adj[parent]){
            if(dfs(child, visited, adj) == false)
                return false;
        }

        visited[parent] = false;
        adj[parent] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }


        vector<bool> visited(numCourses);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, visited, adj) == false)
                    return false;
            }
        }

        return true;
    }
};